class Solution {
public:
  int countCompleteSubarrays(vector<int> &nums) {
    int n = nums.size();
    int l = 0;
    int count = 0;
    unordered_map<int, int> ht;
    unordered_set<int> set(nums.begin(), nums.end());
    int m = set.size();

    for (int i = 0; i < n; i++) {
      ht[nums[i]]++;
      while (ht.size() == m) {
        count += nums.size() - i;
        ht[nums[l]]--;

        if (ht[nums[l]] == 0)
          ht.erase(nums[l]);

        l++;
      }
    }

    return count;

    return count;
  }
};