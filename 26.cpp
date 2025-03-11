#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    vector<int> nNums;
    nNums.push_back(nums[0]);

    for (int i = 0; i < n - 1; i++) {
      if (nums[i] != nums[i + 1])
        nNums.push_back(nums[i + 1]);
    }

    nums = nNums;
    return nNums.size();
  }
};