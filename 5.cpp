class Solution {
public:
  string longestPalindrome(string s) {
    if (s.empty())
      return "";
    int n = s.length();
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
      int l1 = expandAroundCenter(s, i, i);
      int l2 = expandAroundCenter(s, i, i + 1);
      int l = max(l1, l2);

      if (l > maxLen) {
        start = i - (l - 1) / 2;
        maxLen = l;
      }
    }
    return s.substr(start, maxLen);
  }

  int expandAroundCenter(string s, int l, int r) {
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
      l--;
      r++;
    }
    return r - l - 1;
  }
};
