class Solution {
public:
  int romanToInt(string s) {
    int n = s.size();
    int res = 0;

    unordered_map<char, int> val = {{'I', 1},   {'V', 5},   {'X', 10},
                                    {'L', 50},  {'C', 100}, {'D', 500},
                                    {'M', 1000}};

    for (int i = 0; i < n - 1; i++) {
      if (val[s[i]] < val[s[i + 1]]) {
        res -= val[s[i]];
      } else {
        res += val[s[i]];
      }
    }

    return res + val[s[n - 1]];
  }
};