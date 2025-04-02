class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int diff = INT_MAX;
    int val = 0;
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int l = i + 1;
      int r = n - 1;

      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (diff > abs(sum - target)) {
          val = sum;
          diff = abs(sum - target);
        }

        if (sum > target) {
          r--;
        } else if (sum < target) {
          l++;
        } else {
          return target;
        }
      }
    }

    return val;
  }
};