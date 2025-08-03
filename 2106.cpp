class Solution {
public:
  int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int n = fruits.size();

    vector<int> positions, amounts;
    for (auto &i : fruits) {
      positions.push_back(i[0]);
      amounts.push_back(i[1]);
    }

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
      prefix[i + 1] = prefix[i] + amounts[i];

    int ans = 0;

    for (int i = 0, j = 0; i < n; i++) {
      while (j < n) {
        int l = positions[i];
        int r = positions[j];

        int fore = abs(startPos - l) + (r - l);
        int back = abs(startPos - r) + (r - l);
        int steps = min(fore, back);

        if (steps > k)
          break;

        int total = prefix[j + 1] - prefix[i];
        ans = max(ans, total);
        j++;
      }
    }

    return ans;
  }
};
