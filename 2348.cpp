class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long ans = 0;
    long long size = 0;
    for (int i : nums) {
      if (i == 0) {
        size++;
        ans += size;
      } else {
        size = 0;
      }
    }

    return ans;
  }
};