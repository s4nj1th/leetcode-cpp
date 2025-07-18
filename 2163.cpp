class Solution {
public:
  long long minimumDifference(vector<int> &nums) {
    int n = nums.size() / 3;

    vector<long long> p1(n + 1);
    long long sum = 0;
    priority_queue<int> pqL;

    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      pqL.push(nums[i]);
    }

    p1[0] = sum;

    for (int i = n; i < n * 2; ++i) {
      sum += nums[i];
      pqL.push(nums[i]);
      sum -= pqL.top();
      pqL.pop();
      p1[i - (n - 1)] = sum;
    }

    long long p2 = 0;
    priority_queue<int, vector<int>, greater<int>> pqR;
    for (int i = n * 3 - 1; i >= n * 2; --i) {
      p2 += nums[i];
      pqR.push(nums[i]);
    }

    long long ans = p1[n] - p2;
    for (int i = n * 2 - 1; i >= n; --i) {
      p2 += nums[i];
      pqR.push(nums[i]);
      p2 -= pqR.top();
      pqR.pop();
      ans = min(ans, p1[i - n] - p2);
    }

    return ans;
  }
};