class Solution {
public:
  int numberOfArrays(vector<int> &diff, int lower, int upper) {
    long sum = 0, maxI = 0, minI = 0;
    for (int i : diff) {
      sum += i;
      maxI = max(maxI, sum);
      minI = min(minI, sum);
    }
    return max(0L, upper - lower - maxI + minI + 1);
  }
};