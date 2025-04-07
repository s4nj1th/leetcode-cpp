class Solution {
  int totSum(vector<int> arr) {
    int sum = 0;
    for (int i : arr)
      sum += i;
    return sum;
  }

public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    int sum = totSum(nums);

    if (sum % 2 != 0)
      return false;
    sum /= 2;

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));

    for (int i = 0; i < n; i++)
      dp[i][0] = true;

    if (nums[0] <= sum)
      dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= sum; j++) {
        bool no = dp[i - 1][j];
        bool ye = (nums[i] <= j) ? dp[i - 1][j - nums[i]] : 0;
        dp[i][j] = no || ye;
      }
    }

    return dp[n - 1][sum];
  }
};