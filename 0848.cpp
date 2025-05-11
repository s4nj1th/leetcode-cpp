class Solution {
public:
  int numberOfPoints(vector<vector<int>> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int total = nums[0][1] - nums[0][0] + 1;
    int curEnd = nums[0][1];

    for (int i = 1; i < n; i++) {
      if (nums[i][0] <= curEnd) {
        total += max(0, nums[i][1] - curEnd);
        curEnd = max(curEnd, nums[i][1]);
      } else {
        total += nums[i][1] - nums[i][0] + 1;
        curEnd = nums[i][1];
      }
    }

    return total;
  }
};
