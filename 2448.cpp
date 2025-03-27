class Solution {
public:
  long long minCost(vector<int> &nums, vector<int> &cost) {
    int n = nums.size();
    vector<pair<int, int>> nAndCost;

    for (int i = 0; i < n; i++) {
      nAndCost.push_back({nums[i], cost[i]});
    }

    sort(nAndCost.begin(), nAndCost.end());

    long long totC = 0;
    for (auto &[_, c] : nAndCost)
      totC += c;

    long long midVal = 0, accC = 0;
    for (auto &[num, c] : nAndCost) {
      accC += c;
      if (accC >= (totC + 1) / 2) {
        midVal = num;
        break;
      }
    }

    long long res = 0;
    for (auto &[i, c] : nAndCost) {
      res += 1LL * abs(i - midVal) * c;
    }

    return res;
  }
};