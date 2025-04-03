class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    int n = nums.size();
    long long maxVal = 0;

    vector<int> maxDiff(n, 0);
    int maxNum = nums[0];

    for (int j = 1; j < n; j++) {
      maxDiff[j] = max(maxDiff[j - 1], maxNum - nums[j]);
      maxNum = max(maxNum, nums[j]);
    }

    for (int k = 2; k < n; k++) {
      maxVal = max(maxVal, (long long)maxDiff[k - 1] * nums[k]);
    }

    return maxVal;
  }
};
