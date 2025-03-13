class Solution {
public:
  int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    int m = queries.size();

    auto isValid = [&](int k) -> bool {
      vector<int> diff(n + 1, 0);
      vector<int> temp = nums;

      for (int i = 0; i < k; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        int v = queries[i][2];

        diff[l] -= v;
        if (r + 1 < n)
          diff[r + 1] += v;
      }

      int cDec = 0;
      for (int i = 0; i < n; i++) {
        cDec += diff[i];
        temp[i] += cDec;
        if (temp[i] > 0)
          return false;
      }

      return true;
    };

    int l = 0, r = m, res = -1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (isValid(mid)) {
        res = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return res;
  }
};