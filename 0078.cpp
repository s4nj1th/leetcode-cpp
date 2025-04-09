class Solution {
  void genSubs(vector<int> nums, int i, vector<int> &cur,
               vector<vector<int>> &res) {
    if (i == nums.size()) {
      res.push_back(cur);
      return;
    }

    cur.push_back(nums[i]);
    genSubs(nums, i + 1, cur, res);

    cur.pop_back();
    genSubs(nums, i + 1, cur, res);
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> cur;
    vector<vector<int>> res;
    genSubs(nums, 0, cur, res);
    return res;
  }
};