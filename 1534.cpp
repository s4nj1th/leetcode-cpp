// brute force

class Solution {
public:
  int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        if (abs(arr[i] - arr[j]) <= a)
          for (int k = j + 1; k < n; k++) {
            if (abs(arr[j] - arr[k]) <= b && abs(arr[k] - arr[i]) <= c)
              count++;
          }
      }
    }

    return count;
  }
};

// prefix sum

class Solution {
public:
  int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    int ans = 0, n = arr.size();
    vector<int> sum(1001, 0);

    for (int j = 0; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (abs(arr[j] - arr[k]) <= b) {
          int lj = arr[j] - a, rj = arr[j] + a;
          int lk = arr[k] - c, rk = arr[k] + c;
          int l = max(0, max(lj, lk)), r = min(1000, min(rj, rk));
          if (l <= r) {
            if (l == 0)
              ans += sum[r];
            else
              ans += sum[r] - sum[l - 1];
          }
        }
      }
      for (int k = arr[j]; k <= 1000; ++k) {
        ++sum[k];
      }
    }
    return ans;
  }
};
