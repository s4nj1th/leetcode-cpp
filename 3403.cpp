class Solution {
  string finSubstr(string s) {
    int i = 0;
    int j = 1;
    int n = s.size();

    while (j < n) {
      int k = 0;
      while (j + k < n && s[i + k] == s[j + k])
        k++;

      if (j + k < n && s[i + k] < s[j + k]) {
        int t = i;
        i = j;
        j = max(j + 1, t + k + 1);
      } else {
        j = j + k + 1;
      }
    }

    return s.substr(i, n - i);
  }

public:
  string answerString(string word, int num) {
    if (num == 1)
      return word;

    string ans = finSubstr(word);
    int n = word.size();
    int m = ans.size();

    return ans.substr(0, min(m, n - num + 1));
  }
};