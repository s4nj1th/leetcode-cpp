class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    vector<int> num(100);
    int res = 0;
    for (auto &i : dominoes) {
      int val = i[0] < i[1] ? i[0] * 10 + i[1] : i[1] * 10 + i[0];
      res += num[val];
      num[val]++;
    }
    return res;
  }
};