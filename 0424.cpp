
class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();

    if (k >= n)
      return n;
    if (n == 1)
      return n;

    int frAr[26] = {};

    int maxFreq = 0;

    int res = 0;

    int i = 0;
    for (int j = 0; j < n; ++j) {
      frAr[s[j] - 'A']++;
      maxFreq = max(maxFreq, frAr[s[j] - 'A']);

      while ((j - i + 1) - maxFreq > k) {
        frAr[s[i] - 'A']--;
        i++;
      }

      res = max(res, j - i + 1);
    }

    return res;
  }
};
