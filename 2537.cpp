class Solution {
public:
  long long countGood(vector<int> &nums, int k) {
    int n = nums.size();
    int same = 0, r = -1;
    unordered_map<int, int> count;
    long long res = 0;
    for (int l = 0; l < n; l++) {
      while (same < k && r + 1 < n) {
        r++;
        same += count[nums[r]];
        count[nums[r]]++;
      }

      if (same >= k)
        res += n - r;

      count[nums[l]]--;
      same -= count[nums[l]];
    }
    return res;
  }
};