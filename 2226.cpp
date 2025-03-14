class Solution {
public:
  int maximumCandies(vector<int> &candies, long long k) {
    int maxC = candies[0];
    for (int i : candies) {
      if (i > maxC)
        maxC = i;
    }

    int l = 1, r = maxC, res = 0;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      long long tot = 0;

      for (int i : candies) {
        tot += i / mid;
      }

      if (tot >= k) {
        res = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return res;
  }
};