class Solution {
public:
  int maxDivScore(vector<int> &nums, vector<int> &divisors) {
    int n = nums.size();
    int m = divisors.size();
    int res = 0;
    int maxCnt = -1;

    sort(divisors.begin(), divisors.end());

    for (int i = 0; i < m; i++) {
      int cnt = 0;
      int div = divisors[i];
      for (int j = 0; j < n; j++) {
        if (nums[j] % div == 0)
          cnt++;
      }
      if (cnt > maxCnt) {
        res = div;
        maxCnt = cnt;
      } else if (cnt == maxCnt and res > div)
        res = div;
    }
    return res;
  }
};