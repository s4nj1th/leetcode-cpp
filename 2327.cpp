class Solution {
  typedef long long ll;
  const ll MOD = 1e9 + 7;

public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<ll> dp(n + 1, 0);
    dp[1] = 1;
    ll share = 0;

    for (int i = 2; i < n + 1; i++) {
      if (i - delay > 0) {
        share = (share + dp[i - delay] + MOD) % MOD;
      }
      if (i - forget > 0) {
        share = (share - dp[i - forget] + MOD) % MOD;
      }

      dp[i] = share;
    }

    ll know = 0;

    for (int i = n - forget + 1; i < n + 1; i++) {
      know = (know + dp[i]) % MOD;
    }

    return (int)know;
  }
};