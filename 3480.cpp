class Solution {
public:
  long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs) {
    vector<vector<int>> right(n + 1);

    for (auto &i : conflictingPairs) {
      right[max(i[0], i[1])].push_back(min(i[0], i[1]));
    }

    long long ans = 0;
    vector<long long> left = {0, 0};
    vector<long long> bonus(n + 1, 0);

    for (int r = 1; r <= n; r++) {
      for (int lV : right[r]) {
        if (lV > left[0]) {
          left = {(long long)lV, left[0]};
        } else if (lV > left[1]) {
          left = {left[0], (long long)lV};
        }
      }

      ans += r - left[0];

      if (left[0] > 0) {
        bonus[left[0]] += left[0] - left[1];
      }
    }

    return ans + *max_element(bonus.begin(), bonus.end());
  }
};