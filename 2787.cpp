class Solution {
public:
  int numberOfWays(int n, int x) {
    const int MOD = 1e9 + 7;

    vector<int> powers;
    for (int i = 1; pow(i, x) <= n; i++) {
      powers.push_back((int)pow(i, x));
    }

    int m = powers.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
      dp[0][j] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i][j - 1];
        if (i >= powers[j - 1]) {
          dp[i][j] = (dp[i][j] + dp[i - powers[j - 1]][j - 1]) % MOD;
        }
      }
    }

    return dp[n][m];
  }
};
