/*

Qn:
    - prob of A getting over before B
    - .25 prob for (100-0, 75-25, 50-50, 25-75)
    - reduces by the amount simul
    - all prev cases independent from the current one

IP:
    - n -> total amount in A & B

Idea:
    - 4 choices at every point
    - divide into 25ml sections (each section is consumed in every choice (fo
sho))
    -

*/

class Solution {
  double calculateDP(int i, int j,
                     unordered_map<int, unordered_map<int, double>> &dp) {
    if (i <= 0 && j <= 0)
      return 0.5;

    if (i <= 0)
      return 1;

    if (j <= 0)
      return 0;

    if (dp[i].count(j))
      return dp[i][j];

    return dp[i][j] =
               (calculateDP(i - 4, j, dp) + calculateDP(i - 3, j - 1, dp) +
                calculateDP(i - 2, j - 2, dp) + calculateDP(i - 1, j - 3, dp)) /
               4;
  };

public:
  double soupServings(int n) {
    if (n > 4800)
      return 1;

    int m = ceil(n / 25.0);
    unordered_map<int, unordered_map<int, double>> dp;

    for (int k = 1; k <= m; k++) {
      if (calculateDP(k, k, dp) > 1 - 1e-5) {
        return 1;
      }
    }
    return calculateDP(m, m, dp);
  }
};