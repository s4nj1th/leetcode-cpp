class Solution {
public:
  int maxSum(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    sort(nums.begin(), nums.end());
    int sum = nums[n - 1];

    vector<int> ht(201, 0);
    ht[n - 1]++;

    int prev = nums[n - 1];
    int i = n - 1;
    while (i >= 0 && nums[i] > 0) {
      if (prev != nums[i]) {
        prev = nums[i];
        sum += nums[i];
      }
      i--;
    }

    return sum;
  }
};