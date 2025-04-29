class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    long long count = 0;
    int maxCount = 0;
    int l = 0;

    int maxE = *max_element(nums.begin(), nums.end());

    for (int r = 0; r < n; r++) {
      if (nums[r] == maxE)
        maxCount++;

      while (maxCount >= k) {
        count += n - r;
        if (nums[l] == maxE)
          maxCount--;
        l++;
      }
    }

    return count;
  }
};
