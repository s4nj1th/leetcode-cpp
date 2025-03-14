class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int n = piles.size();

    int maxP = piles[0];
    for (int i : piles) {
      if (i > maxP)
        maxP = i;
    }

    int l = 1, r = maxP, res = maxP;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      long long tot = 0;

      for (int i : piles) {
        tot += (i + mid - 1) / mid;
      }

      if (tot <= h) {
        res = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return res;
  }
};