class Solution {
public:
  int minKBitFlips(vector<int> &nums, int k) {
    int n = nums.size();
    vector<bool> flipped(n, 0);
    int valFlips = 0;
    int ops = 0;

    for (int i = 0; i < n; i++) {
      if (i >= k) {
        if (flipped[i - k]) {
          valFlips--;
        }
      }

      if (valFlips % 2 == nums[i]) {
        if (i + k > n)
          return -1;

        valFlips++;
        flipped[i] = 1;
        ops++;
      }
    }

    return ops;
  }
};