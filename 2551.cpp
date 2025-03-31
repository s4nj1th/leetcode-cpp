class Solution {
public:
  long long putMarbles(vector<int> &weights, int k) {
    long long n = weights.size();
    long long res = 0;

    for (int i = 0; i < n - 1; i++) {
      weights[i] += weights[i + 1];
    }
    weights.pop_back();

    sort(weights.begin(), weights.end());

    for (int i = 0; i < k - 1; i++) {
      res += weights[n - 1 - i - 1] - weights[i];
    }

    return res;
  }
};