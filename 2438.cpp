class Solution {
public:
  vector<int> productQueries(int n, vector<vector<int>> &queries) {
    vector<long long> powers;
    long long val = 1, mod = 1e9 + 7;

    for (int i = 0; i < 32; i++) {
      if (n & (1 << i))
        powers.push_back(val);
      val *= 2;
      val %= mod;
    }

    vector<int> ans;
    for (auto &i : queries) {
      long long pdt = 1;

      for (int j = i[0]; j <= i[1]; j++) {
        pdt *= powers[j];
        pdt %= mod;
      }

      ans.push_back(pdt);
    }

    return ans;
  }
};