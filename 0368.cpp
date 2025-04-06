class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    int maxI = 0;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
        maxI = (dp[i] > dp[maxI]) ? i : maxI;
      }
    }

    vector<int> res;
    while (maxI != -1) {
      res.push_back(nums[maxI]);
      maxI = prev[maxI];
    }

    return res;
  }
};