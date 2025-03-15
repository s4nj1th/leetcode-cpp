class Solution {
  bool canRob(vector<int> &nums, int k, int maxCap) {
    int c = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] <= maxCap) {
        c++;
        i++;
      }
      if (c >= k)
        return true;
    }
    return false;
  }

public:
  int minCapability(vector<int> &nums, int k) {
    int n = nums.size();

    int l = nums[0];
    int r = nums[0];
    for (int i : nums) {
      if (i < l)
        l = i;
      if (i > r)
        r = i;
    }
    int res = r;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (canRob(nums, k, mid)) {
        res = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return res;
  }
};