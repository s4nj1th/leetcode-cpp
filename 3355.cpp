class Solution {
public:
  bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    int m = queries.size();

    vector<int> diff(n + 1, 0);

    for (int i = 0; i < m; i++) {
      int l = queries[i][0];
      int r = queries[i][1];

      diff[l]--;
      if (r + 1 < n)
        diff[r + 1]++;
    }

    int cDec = 0;
    for (int i = 0; i < n; i++) {
      cDec += diff[i];
      if (nums[i] + cDec > 0)
        return false;
    }

    return true;
  }
};