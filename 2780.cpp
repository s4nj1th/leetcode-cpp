class Solution {
public:
  int minimumIndex(vector<int> &nums) {
    int n = nums.size();
    vector<int> nums2 = nums;
    sort(nums2.begin(), nums2.end());

    int val = nums2[n / 2];
    int totV = count(nums.begin(), nums.end(), val);
    int lc = 0, rc = totV - lc;

    for (int i = 0; i < n; i++) {
      if (nums[i] == val) {
        lc++;
        rc--;
      }
      if (2 * lc > i + 1 && 2 * rc > n - i - 1)
        return i;
    }
    return -1;
  }
};