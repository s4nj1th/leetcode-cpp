class Solution {
public:
  int numRabbits(vector<int> &nums, int total = 0) {
    unordered_map<int, int> mpp;

    for (int i : nums)
      mpp[i]++;

    for (auto &i : mpp)
      total += ceil((double)i.second / (i.first + 1)) * (i.first + 1);

    return total;
  }
};