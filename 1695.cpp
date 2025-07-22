class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = 0, maxSum = 0, curSum = 0;
    vector<int> ht(10001, -1);

    while (r < n) {
      if (ht[nums[r]] != -1) {
        while (l <= ht[nums[r]]) {
          curSum -= nums[l];
          l++;
        }
      }
      curSum += nums[r];
      maxSum = max(maxSum, curSum);
      ht[nums[r]] = r;
      r++;
    }

    return maxSum;
  }
};