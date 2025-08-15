class Solution {
public:
  bool isPowerOfFour(int n) {
    if (n == 1)
      return true;
    if (n <= 0 || n & 1)
      return false;

    for (int i = 0; i < 31; i += 2) {
      if ((1 << i) == n)
        return true;
    }

    return false;
  }
};