class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int l = 0;
    int maxL = 0;
    int n = s.size();
    unordered_map<char, int> ht;

    for (int r = 0; r < n; r++) {
      char c = s[r];
      ht[c]++;

      while (ht[c] > 1) {
        char lC = s[l];
        ht[lC]--;
        l++;
      }

      maxL = max(maxL, r - l + 1);
    }

    return maxL;
  }
};