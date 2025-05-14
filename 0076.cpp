class Solution {
public:
  string minWindow(string s, string t) {
    if (t.size() > s.size())
      return "";

    unordered_map<char, int> tFreq, window;
    for (char c : t)
      tFreq[c]++;

    int have = 0, need = tFreq.size();
    int l = 0, minLen = INT_MAX, minStart = 0;

    for (int r = 0; r < s.size(); r++) {
      char c = s[r];
      window[c]++;

      if (tFreq.count(c) && window[c] == tFreq[c])
        have++;

      while (have == need) {
        if (r - l + 1 < minLen) {
          minLen = r - l + 1;
          minStart = l;
        }

        char lChar = s[l];
        window[lChar]--;
        if (tFreq.count(lChar) && window[lChar] < tFreq[lChar])
          have--;

        l++;
      }
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
  }
};
