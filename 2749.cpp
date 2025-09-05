class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    for (int i = 0; i < 61; i++) {
      long long x = (long long)num1 - (long long)num2 * i;
      if (x < i)
        return -1;

      if (i >= __builtin_popcountll(x))
        return i;
    }

    return -1;
  }
};
