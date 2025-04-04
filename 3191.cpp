class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    int operations = 0;

    for (int i = 0; i <= n - 3; i++) {
      if (nums[i] == 0) {
        nums[i] = !nums[i];
        nums[i + 1] = !nums[i + 1];
        nums[i + 2] = !nums[i + 2];
        operations++;
      }
    }

    for (int i = n - 2; i < n; i++) {
      if (nums[i] == 0)
        return -1;
    }

    return operations;
  }
};

/*
- flip all elements to 1
- simple way to do this would be simple linear approach
*/
