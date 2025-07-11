class Solution {
public:
  int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
    int n = startTime.size();
    int ans = 0;

    for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
      int l1 = i == 0 ? 0 : endTime[i - 1];
      int r1 = i == n - 1 ? eventTime : startTime[i + 1];

      if (endTime[i] - startTime[i] <= t1) {
        ans = max(ans, r1 - l1);
      }

      t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

      ans = max(ans, r1 - l1 - (endTime[i] - startTime[i]));

      int l2 = i == n - 1 ? 0 : endTime[n - i - 2];
      int r2 = i == 0 ? eventTime : startTime[n - i];

      if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
        ans = max(ans, r2 - l2);
      }

      t2 =
          max(t2, (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
    }
    return ans;
  }
};

// incorrect commit name
