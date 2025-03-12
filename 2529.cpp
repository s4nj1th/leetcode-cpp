class Solution {
public:
  int maximumCount(vector<int> &nums) {
    int cp = 0;
    int cn = 0;

    for (int i : nums) {
      if (i > 0)
        cp++;
      if (i < 0)
        cn++;
    }

    return max(cp, cn);
  }
};