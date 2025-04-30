class Solution {
public:
  int findNumbers(vector<int> &nums) {
    int count = 0;

    for (int i : nums) {
      if ((i >= 10 && i <= 99) || (i >= 1000 && i <= 9999) || i == 100000)
        count++;
    }

    return count;
  }
};