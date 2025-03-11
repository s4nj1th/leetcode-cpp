#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int low = prices[0];
    int high = prices[0];
    int profit = 0;

    for (int i : prices) {
      if (i < low) {
        low = i;
        high = i;
      }
      if (i > high)
        high = i;

      profit = max(high - low, profit);
    }

    return profit;
  }
};