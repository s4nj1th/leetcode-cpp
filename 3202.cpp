class Solution {
public:
  int maximumLength(vector<int> &nums, int k) {
    vector<vector<int>> dp(k, vector<int>(k, 0));
    int res = 0;
    for (int i : nums) {
      i %= k;
      for (int j = 0; j < k; ++j) {
        dp[j][i] = dp[i][j] + 1;
        res = max(res, dp[j][i]);
      }
    }
    return res;
  }
};