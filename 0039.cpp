class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> comb;
    combos(candidates, target, 0, comb, 0, res);
    return res;
  }

private:
  void combos(vector<int> &candidates, int target, int idx, vector<int> &comb,
              int total, vector<vector<int>> &res) {
    if (total == target) {
      res.push_back(comb);
      return;
    }

    if (total > target || idx >= candidates.size()) {
      return;
    }

    comb.push_back(candidates[idx]);
    combos(candidates, target, idx, comb, total + candidates[idx], res);
    comb.pop_back();
    combos(candidates, target, idx + 1, comb, total, res);
  }
};