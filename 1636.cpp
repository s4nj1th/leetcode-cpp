class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> ht;
    for (int i : nums) {
      ht[i]++;
    }

    sort(nums.begin(), nums.end(), [&](int a, int b) {
      if (ht[a] == ht[b])
        return a > b;
      return ht[a] < ht[b];
    });

    return nums;
  }
};