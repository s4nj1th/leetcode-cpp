class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    int n = nums.size();
    int bit = 0;

    for (int i : nums) {
      bit |= i;
    }

    return bit << n - 1;
  }
};