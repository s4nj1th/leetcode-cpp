class Solution {
  void getPerms(vector<vector<int>> &res, vector<int> &nums, int i, int n) {
    if (i == n) {
      res.push_back(nums);
      return;
    }

    unordered_map<int, int> ht;
    for (int j = i; j < n; j++) {
      if (ht[nums[j]])
        continue;
      ht[nums[j]]++;

      swap(nums[i], nums[j]);
      getPerms(res, nums, i + 1, n);
      swap(nums[i], nums[j]);
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> res;
    getPerms(res, nums, 0, n);
    return res;
  }
};