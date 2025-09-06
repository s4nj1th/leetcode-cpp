class Solution {
  long long fn(int x) {
    int i = 1;
    int n = 1;

    long long ans = 0;

    while (n <= x) {
      ans += 1LL * (i + 1) / 2 * (min(n * 2 - 1, x) - n + 1);
      i++;
      n *= 2;
    }

    return ans;
  }

public:
  long long minOperations(vector<vector<int>> &queries) {
    long long ans = 0;

    for (auto &i : queries) {
      ans += (fn(i[1]) - fn(i[0] - 1) + 1) / 2;
    }

    return ans;
  }
};