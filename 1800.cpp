class Solution {
public:
  int maxAscendingSum(vector<int> &nums) {
    int cur = nums[0];
    int res = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      cur = nums[i] > nums[i - 1] ? cur + nums[i] : nums[i];
      res = max(res, cur);
    }
    return res;
  }
};