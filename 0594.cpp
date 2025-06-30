class Solution {
public:
  int findLHS(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int j = 0, maxL = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      while (nums[i] - nums[j] > 1) {
        ++j;
      }
      if (nums[i] - nums[j] == 1) {
        maxL = max(maxL, i - j + 1);
      }
    }
    return maxL;
  }
};