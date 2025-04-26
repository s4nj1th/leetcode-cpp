class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    if (zero > one)
      return countGoodStrings(low, high, one, zero);

    int mod = 1e9 + 7;

    vector<int> dp(high + 1, 0);
    dp[0] = 1;
    int res = 0;

    for (int i = 1; i <= high; i++) {
      if (i >= zero)
        dp[i] = (dp[i] + dp[i - zero]) % mod;
      if (i >= one)
        dp[i] = (dp[i] + dp[i - one]) % mod;
      if (i >= low)
        res += dp[i];
      res %= mod;
    }

    return res;
  }
};