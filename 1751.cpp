class Solution {
public:
  int maxValue(vector<vector<int>> &events, int k) {
    int n = events.size();

    sort(
        events.begin(), events.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    vector<int> endTimes;
    for (const auto &i : events) {
      endTimes.push_back(i[1]);
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; ++i) {
      int start = events[i - 1][0];
      int end = events[i - 1][1];
      int value = events[i - 1][2];

      int prevIndex = lower_bound(endTimes.begin(), endTimes.end(), start) -
                      endTimes.begin();

      for (int j = 1; j <= k; ++j) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        dp[i][j] = max(dp[i][j], dp[prevIndex][j - 1] + value);
      }
    }

    return dp[n][k];
  }
};