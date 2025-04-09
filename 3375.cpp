class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    unordered_map<int, int> htc;
    int c = 0;

    for (int i : nums) {
      if (i < k)
        return -1;
      if (i > k)
        htc[i]++;
      if (htc[i] == 1)
        c++;
    }

    return c;
  }
};