class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    int maxLen = 0;
    int l = 0;
    int noOfZ = 0;
    for (int r = 0; r < n; r++) {
      if (nums[r] == 0)
        noOfZ++;

      while (noOfZ > 1) {
        if (nums[l] == 0)
          noOfZ--;
        l++;
      }

      maxLen = max(r - l - noOfZ + 1, maxLen);
    }

    return (maxLen == n) ? maxLen - 1 : maxLen;
  }
};