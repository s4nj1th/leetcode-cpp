class Solution {
public:
  const int MOD = 1e9 + 7;

  vector<vector<int>> generatePatterns(int m) {
    vector<vector<int>> patterns;

    function<void(vector<int> &)> backtrack = [&](vector<int> &curr) {
      if (curr.size() == m) {
        patterns.push_back(curr);
        return;
      }
      for (int c = 0; c < 3; ++c) {
        if (curr.empty() || c != curr.back()) {
          curr.push_back(c);
          backtrack(curr);
          curr.pop_back();
        }
      }
    };

    vector<int> curr;
    backtrack(curr);
    return patterns;
  }

  int colorTheGrid(int m, int n) {
    auto patterns = generatePatterns(m);
    int sz = patterns.size();

    unordered_map<int, vector<int>> transitions;
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        bool ok = true;
        for (int k = 0; k < m; ++k) {
          if (patterns[i][k] == patterns[j][k]) {
            ok = false;
            break;
          }
        }
        if (ok)
          transitions[i].push_back(j);
      }
    }

    vector<long long> dp(sz, 1);
    vector<long long> new_dp(sz);

    for (int col = 1; col < n; ++col) {
      fill(new_dp.begin(), new_dp.end(), 0);
      for (int i = 0; i < sz; ++i) {
        for (int next : transitions[i]) {
          new_dp[next] = (new_dp[next] + dp[i]) % MOD;
        }
      }
      dp = new_dp;
    }

    long long res = 0;
    for (long long val : dp) {
      res = (res + val) % MOD;
    }

    return (int)res;
  }
};
