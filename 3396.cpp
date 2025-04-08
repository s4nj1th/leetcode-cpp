class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int n = nums.size();

    unordered_map<int, bool> htc;

    for (int i = n - 1; i >= 0; i--) {
      if (htc[nums[i]])
        return i / 3 + 1;
      htc[nums[i]] = 1;
    }

    return 0;
  }
};