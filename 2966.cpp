class Solution {
public:
  vector<vector<int>> divideArray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<vector<int>> ls;
    sort(nums.begin(), nums.end());

    int i = 0;
    while (i < n - 2) {
      if (nums[i + 2] - nums[i] <= k) {
        ls.push_back({nums[i], nums[i + 1], nums[i + 2]});
        i += 3;
      } else {
        return {};
      }
    }

    return ls;
  }
};