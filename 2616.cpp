class Solution {
public:
  int countValidPairs(vector<int> &nums, int key) {
    int index = 0, count = 0;
    while (index < nums.size() - 1) {
      if (nums[index + 1] - nums[index] <= key) {
        count++;
        index++;
      }
      index++;
    }
    return count;
  }

  int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = nums[n - 1] - nums[0];

    while (l < r) {
      int m = l + (r - l) / 2;

      if (countValidPairs(nums, m) >= p) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};