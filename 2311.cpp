class Solution {
public:
  int longestSubsequence(string s, int k) {
    int small = 0;
    int count = 0;
    int n = s.size();
    int bits = 32 - __builtin_clz(k);
    for (int i = 0; i < n; ++i) {
      char c = s[n - 1 - i];
      if (c == '1') {
        if (i < bits && small + (1 << i) <= k) {
          small += 1 << i;
          count++;
        }
      } else {
        count++;
      }
    }
    return count;
  }
};