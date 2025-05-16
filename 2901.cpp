class Solution {
  bool oneOff(string &s1, string &s2) {
    if (s1.size() != s2.size())
      return false;
    int diff = 0;
    for (int i = 0; i < s1.size(); i++)
      if (s1[i] != s2[i] && ++diff > 1)
        return false;
    return diff == 1;
  }

public:
  vector<string> getWordsInLongestSubsequence(vector<string> &words,
                                              vector<int> &groups) {
    int n = words.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);

    int maxLen = 1;
    int lastIndex = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (groups[i] != groups[j] && words[i].size() == words[j].size() &&
            oneOff(words[i], words[j])) {

          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            prev[i] = j;
          }
        }
      }
      if (dp[i] > maxLen) {
        maxLen = dp[i];
        lastIndex = i;
      }
    }

    vector<string> res;
    for (int i = lastIndex; i != -1; i = prev[i])
      res.push_back(words[i]);
    reverse(res.begin(), res.end());
    return res;
  }
};