class Solution {
public:
  string largestGoodInteger(string num) {
    string s = "";
    int n = num.size();

    for (int i = 0; i < n - 2; i++) {
      if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
        string t = string(3, num[i]);
        if (s.empty() || t > s) {
          s = t;
        }
      }
    }

    return s;
  }
};
