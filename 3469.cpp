class Solution {
  int calc(int ext, int ind, vector<int> &nums, vector<vector<int>> &dp) {
    if (ind == nums.size())
      return nums[ext];

    if (ind == nums.size() - 1)
      return max(nums[ext], nums[ind]);

    if (dp[ind][ext] != -1)
      return dp[ind][ext];

    int fst = max(nums[ind], nums[ind + 1]) + calc(ext, ind + 2, nums, dp);
    int snd = max(nums[ext], nums[ind + 1]) + calc(ind, ind + 2, nums, dp);
    int thd = max(nums[ext], nums[ind]) + calc(ind + 1, ind + 2, nums, dp);

    return dp[ind][ext] = min({fst, snd, thd});
  }

public:
  int minCost(vector<int> &nums) {
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return calc(0, 1, nums, dp);
  }
};