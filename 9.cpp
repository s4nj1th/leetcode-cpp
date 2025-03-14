class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    long long pal = 0;
    long long y = x;
    while (y != 0) {
      pal *= 10;
      pal += y % 10;
      y /= 10;
    }

    return (x == pal);
  }
};