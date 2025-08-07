class Solution {
public:
  int minCost(int n, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));

    for (int i = 2; i < m; i++) {
      for (int l = 0; l < m - i; l++) {
        int r = l + i;
        dp[l][r] = INT_MAX;

        for (int k = l + 1; k < r; ++k) {
          dp[l][r] = min(dp[l][r], cuts[r] - cuts[l] + dp[l][k] + dp[k][r]);
        }
      }
    }
    return dp[0][m - 1];
  }
};