class Solution {
  char lessChar(char c) { return c == 'a' ? 'z' : char(c - 1); }

public:
  bool canMakeSubsequence(const string &str1, const string &str2) {
    int i = 0;
    int j = 0;

    int n = str1.size();
    int m = str2.size();

    while (i < n && j < m) {
      if (str1[i] == lessChar(str2[j]) || str1[i] == str2[j]) {
        j++;
      }
      i++;
    }

    return j == m;
  }
};