class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> preSum(n, 0);
    vector<bool> res;

    for (int i = 0; i < n - 1; i++) {
      if (nums[i] % 2 == nums[i + 1] % 2) {
        preSum[i + 1] = preSum[i] + 1;
      } else {
        preSum[i + 1] = preSum[i];
      }
    }

    for (auto &q : queries) {
      int l = q[0], r = q[1];
      if (preSum[r] - preSum[l] == 0) {
        res.push_back(true);
      } else {
        res.push_back(false);
      }
    }

    return res;
  }
};
