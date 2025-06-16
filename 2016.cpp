class Solution {
public:
  int maximumDifference(vector<int> &nums) {
    int n = nums.size();
    int minE = nums[0];
    int maxDiff = 0;

    for (int i = 0; i < n; i++) {
      minE = min(minE, nums[i]);
      maxDiff = max(maxDiff, nums[i] - minE);
    }

    return maxDiff ? maxDiff : -1;
  }
};