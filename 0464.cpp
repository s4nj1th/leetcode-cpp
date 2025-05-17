class Solution {
public:
  unordered_map<int, bool> memo;

  bool canWin(int mask, int mx, int total, int desired) {
    if (memo.count(mask))
      return memo[mask];

    for (int i = 0; i < mx; ++i) {
      if (!(mask & (1 << i))) {
        int next = mask | (1 << i);
        if (i + 1 >= desired ||
            !canWin(next, mx, total + i + 1, desired - (i + 1))) {
          return memo[mask] = true;
        }
      }
    }

    return memo[mask] = false;
  }

  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
    if (sum < desiredTotal)
      return false;
    if (desiredTotal <= 0)
      return true;

    return canWin(0, maxChoosableInteger, 0, desiredTotal);
  }
};
