class Solution {
  unordered_map<string, int> memo;
  int x;

  int cost(int i) { return i > 0 ? i : 2; }

  int dp(int i, int target) {
    string key = to_string(i) + "#" + to_string(target);
    if (memo.count(key))
      return memo[key];

    int res;
    if (target == 0) {
      res = 0;
    } else if (target == 1) {
      res = cost(i);
    } else if (i >= 39) {
      res = target + 1;
    } else {
      int t = target / x;
      int r = target % x;
      res =
          min(r * cost(i) + dp(i + 1, t), (x - r) * cost(i) + dp(i + 1, t + 1));
    }

    memo[key] = res;
    return res;
  }

public:
  int leastOpsExpressTarget(int x, int target) {
    this->x = x;
    memo.clear();
    return dp(0, target) - 1;
  }
};
