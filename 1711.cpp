class Solution {
public:
  int countPairs(vector<int> &deliciousness) {
    unordered_map<int, int> lks;
    long long res = 0;
    for (int x : deliciousness) {
      for (int i = 1; i <= (1 << 21); i *= 2) {
        if (lks.count(i - x))
          res += lks[i - x];
      }
      lks[x] += 1;
    }
    return res % (int)(1e9 + 7);
  }
};