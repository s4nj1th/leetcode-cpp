class Solution {
public:
  bool divideArray(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= n - 1; i += 2) {
      if (nums[i] != nums[i + 1])
        return false;
    }
    return true;
  }
};

// another way (using hash table)
class Solution {
public:
  bool divideArray(vector<int> &nums) {
    unordered_map<int, int> ht;
    for (int i : nums) {
      ht[i]++;
    }

    for (auto &[x, y] : ht) {
      if (y % 2 != 0)
        return false;
    }

    return true;
  }
};