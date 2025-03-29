class Solution {
public:
  const int MOD = 1e9 + 7;

  int primeFactors(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        count++;
        while (n % i == 0)
          n /= i;
      }
    }
    if (n > 1)
      count++;
    return count;
  }

  long long modular_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
      if (exp % 2 == 1)
        result = (result * base) % mod;
      base = (base * base) % mod;
      exp /= 2;
    }
    return result;
  }

  int maximumScore(vector<int> &nums, int k) {
    int n = nums.size();
    vector<tuple<int, int, int>> arr;

    for (int i = 0; i < n; i++) {
      arr.emplace_back(i, primeFactors(nums[i]), nums[i]);
    }

    vector<int> left(n, -1), right(n, n);
    stack<pair<int, int>> stk;

    for (auto &[i, f, x] : arr) {
      while (!stk.empty() && stk.top().first < f) {
        stk.pop();
      }
      if (!stk.empty())
        left[i] = stk.top().second;
      stk.push({f, i});
    }

    while (!stk.empty())
      stk.pop();

    for (int j = n - 1; j >= 0; j--) {
      auto [i, f, x] = arr[j];
      while (!stk.empty() && stk.top().first <= f) {
        stk.pop();
      }
      if (!stk.empty())
        right[i] = stk.top().second;
      stk.push({f, i});
    }

    sort(arr.begin(), arr.end(),
         [](auto &a, auto &b) { return get<2>(a) > get<2>(b); });

    long long ans = 1;
    for (auto &[i, f, x] : arr) {
      long long l = left[i], r = right[i];
      long long cnt = (i - l) * (r - i);
      if (cnt <= k) {
        ans = (ans * modular_pow(x, cnt, MOD)) % MOD;
        k -= cnt;
      } else {
        ans = (ans * modular_pow(x, k, MOD)) % MOD;
        break;
      }
    }

    return ans;
  }
};
