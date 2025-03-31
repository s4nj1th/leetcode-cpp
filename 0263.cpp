class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = s.size();
    vector<int> lastTime(26, 0);
    vector<int> pSize;

    for (int i = 0; i < n; i++) {
      lastTime[s[i] - 'a'] = i;
    }

    int pStart = 0, pEnd = 0;
    for (int i = 0; i < n; i++) {
      pEnd = max(pEnd, lastTime[s[i] - 'a']);

      if (i == pEnd) {
        pSize.push_back(pEnd - pStart + 1);
        pStart = i + 1;
      }
    }

    return pSize;
  }
};
