class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    string s;
    int n = text.size();

    vector<bool> broke(26, false);

    for (char i : brokenLetters) {
      broke[i - 'a'] = true;
    }

    int ans = 0;

    int i = 0;
    while (i < n) {
      bool flag = true;
      while (i < n && text[i] != ' ') {
        if (broke[text[i] - 'a']) {
          flag = false;
        }
        i++;
      }

      if (flag)
        ans++;
      i++;
    }

    return ans;
  }
};