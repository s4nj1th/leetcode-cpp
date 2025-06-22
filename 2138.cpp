class Solution {
public:
  vector<string> divideString(string s, int k, char fill) {
    vector<string> l;
    int n = s.size();

    if (n % k != 0) {
      while (n % k != 0) {
        s += fill;
        n++;
      }
    }

    for (int i = 0; i < n; i += k) {
      l.push_back(s.substr(i, k));
    }

    return l;
  }
};