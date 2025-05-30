class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> sum4;

    for (int i = 0; i < n - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      for (int j = i + 1; j < n - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;

        int l = j + 1, r = n - 1;

        while (l < r) {
          long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

          if (sum == target) {
            sum4.push_back({nums[i], nums[j], nums[l], nums[r]});
            l++;
            r--;

            while (l < r && nums[l] == nums[l - 1])
              l++;
            while (l < r && nums[r] == nums[r + 1])
              r--;

          }

          else if (sum < target)
            l++;
          else
            r--;
        }
      }
    }

    return sum4;
  }
};