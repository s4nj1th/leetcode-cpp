class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
      arr.emplace_back(nums[i], i);
    }

    sort(arr.begin(), arr.end());

    long long count = 0;

    count =
        countPairsWithSumLEQ(arr, upper) - countPairsWithSumLEQ(arr, lower - 1);

    return count;
  }

private:
  long long countPairsWithSumLEQ(const vector<pair<int, int>> &arr, int bound) {
    int n = arr.size();
    long long count = 0;
    int j = n - 1;

    for (int i = 0; i < n; i++) {
      while (i < j && arr[i].first + arr[j].first > bound) {
        j--;
      }
      if (i < j) {
        count += (j - i);
      }
    }
    return count;
  }
};
