class Solution {
public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int n = baskets.size();
    int m = sqrt(n);
    int section = (n + m - 1) / m;
    int ans = 0;

    vector<int> maxV(section);
    for (int i = 0; i < n; i++) {
      maxV[i / m] = max(maxV[i / m], baskets[i]);
    }

    for (int i : fruits) {
      int notPlaced = 1;

      for (int j = 0; j < section; j++) {
        if (maxV[j] < i) {
          continue;
        }
        int choose = 0;
        maxV[j] = 0;

        for (int k = 0; k < m; k++) {
          int pos = j * m + k;
          if (pos < n && baskets[pos] >= i && !choose) {
            baskets[pos] = 0;
            choose = 1;
          }
          if (pos < n)
            maxV[j] = max(maxV[j], baskets[pos]);
        }

        notPlaced = 0;
        break;
      }
      ans += notPlaced;
    }

    return ans;
  }
};