class Solution {
public:
  long long countPairs(vector<int> &nums, int k) {
    unordered_map<int, int> gcdFreq;
    long long count = 0;

    for (int i : nums) {
      int g = gcd(i, k);

      for (auto &j : gcdFreq) {
        if ((1LL * g * j.first) % k == 0) {
          count += j.second;
        }
      }

      gcdFreq[g]++;
    }

    return count;
  }
};