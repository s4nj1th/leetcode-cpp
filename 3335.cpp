class Solution {
public:
  int lengthAfterTrresformations(string s, int t) {
    int MOD = 1e9 + 7;

    long cnts[26] = {};

    for (char c : s)
      ++cnts[c - 'a'];

    while (t >= 26) {
      long tmp[26] = {};

      for (int i = 0; i < 25; ++i)
        tmp[i + 1] += cnts[i];

      tmp[0] += cnts[25];
      tmp[1] += cnts[25];

      for (int i = 0; i < 26; ++i) {
        cnts[i] += tmp[i];
        cnts[i] %= MOD;
      }

      t -= 26;
    }

    long res = 0;
    for (int i = 0; i < 26; ++i) {
      res += cnts[i];
      if (i + t >= 26)
        res += cnts[i];
      res %= MOD;
    }
    return res % MOD;
  }
};