class Solution {
  bool isPrefixAndSuffix(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    if (m < n)
      return false;

    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i])
        return false;
      if (s1[n - i - 1] != s2[m - i - 1])
        return false;
    }

    return true;
  }

public:
  int countPrefixSuffixPairs(vector<string> &words) {
    int n = words.size(), count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (isPrefixAndSuffix(words[i], words[j])) {
          count++;
        }
      }
    }
    return count;
  }
};