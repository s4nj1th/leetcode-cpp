class Solution {
public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int n = fruits.size();
    vector<bool> assgn(n, false);

    int missing = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (assgn[j] == 0 && fruits[i] <= baskets[j]) {
          assgn[j] = 1;
          break;
        } else if (j == (n - 1)) {
          ++missing;
        }
      }
    }
    return missing;
  }
};