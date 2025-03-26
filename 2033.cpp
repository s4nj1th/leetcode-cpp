class Solution {
public:
  int minOperations(vector<vector<int>> &grid, int x) {
    int m = grid.size();
    int n = grid[0].size();
    int rem = grid[0][0] % x;
    vector<int> arr;
    for (vector<int> i : grid) {
      for (int j : i) {
        if (j % x != rem)
          return -1;
        arr.push_back(j);
      }
    }
    sort(arr.begin(), arr.end());

    int ops = 0;
    int finCom = arr[m * n / 2];
    for (int i : arr) {
      ops += abs(finCom - i) / x;
    }
    return ops;
  }
};