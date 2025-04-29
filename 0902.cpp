class Solution {
public:
  int atMostNGivenDigitSet(vector<string> &digits, int n) {
    string s = to_string(n);
    int l = s.size();
    int m = digits.size();
    vector<int> dp(l + 1, 0);
    dp[l] = 1;

    for (int i = l - 1; i >= 0; i--) {
      int si = s[i] - '0';
      for (auto j : digits) {
        if (j[0] - '0' < si) {
          dp[i] += pow(m, l - i - 1);
        } else if (j[0] - '0' == si) {
          dp[i] += dp[i + 1];
        }
      }
    }

    for (int i = 1; i < l; i++) {
      dp[0] += pow(m, i);
    }

    return dp[0];
  }
};