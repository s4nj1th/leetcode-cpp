class Solution {
  bool noZero(int x) {
    while (x > 0) {
      if (x % 10 == 0)
        return false;
      x /= 10;
    }
    return true;
  }

public:
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i < n; i++) {
      if (noZero(i) && noZero(n - i))
        return {i, n - i};
    }

    return {};
  }
};