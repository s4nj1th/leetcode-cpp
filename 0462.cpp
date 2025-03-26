class Solution {
public:
  int minMoves2(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int val = nums[n / 2];
    int ops = 0;
    for (int i : nums) {
      ops += abs(val - i);
    }

    return ops;
  }
};