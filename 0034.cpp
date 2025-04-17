class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> result = {-1, -1};
    int l = binSer(nums, target, true);
    int r = binSer(nums, target, false);
    result[0] = l;
    result[1] = r;
    return {l, r};
  }

  int binSer(vector<int> &nums, int target, bool lOrR) {
    int l = 0;
    int r = nums.size() - 1;
    int idx = -1;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (nums[mid] > target) {
        r = mid - 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        idx = mid;
        if (lOrR) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
    }

    return idx;
  }
};