class Solution {
public:
  int minMoves(vector<int> &nums) {
    int minN = nums[0];
    for (int i : nums) {
      minN = (i < minN) ? i : minN;
    }

    int res = 0;
    for (int i : nums) {
      res += i - minN;
    }

    return res;
  }
};