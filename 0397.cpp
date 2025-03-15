class Solution {
public:
  int integerReplacement(long long n) {
    if (n == 1)
      return 0;
    if (n == 0 || n == 2)
      return 1;
    if (n % 2 == 0)
      return integerReplacement(n / 2) + 1;
    return min(integerReplacement((n - 1) / 2),
               integerReplacement((n + 1) / 2)) +
           2;
  }
};