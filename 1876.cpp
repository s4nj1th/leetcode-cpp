class Solution {
public:
  int countGoodSubstrings(string s) {
    int n = s.size();
    if (n < 3)
      return 0;

    int res = 0;
    for (int i = 0; i <= n - 3; ++i) {
      char a = s[i], b = s[i + 1], c = s[i + 2];
      if (a != b && b != c && a != c) {
        res++;
      }
    }
    return res;
  }
};
