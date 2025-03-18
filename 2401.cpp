class Solution {
public:
  int longestNiceSubarray(vector<int> &nums) {
    int l = 0;
    int n = nums.size();
    int bitM = 0;
    int maxL = 0;

    for (int r = 0; r < n; r++) {
      while ((bitM & nums[r]) != 0) {
        bitM ^= nums[l];
        l++;
      }

      bitM |= nums[r];
      maxL = max(maxL, r - l + 1);
    }

    return maxL;
  }
};