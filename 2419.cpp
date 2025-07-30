class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int maxE = 0;
    int l = 0;
    int maxL = 0;

    for (int i : nums) {
      if (maxE < i) {
        maxE = i;
        maxL = 0;
        l = 0;
      }

      if (maxE == i) {
        l++;
      } else {
        l = 0;
      }

      maxL = max(maxL, l);
    }

    return maxL;
  }
};