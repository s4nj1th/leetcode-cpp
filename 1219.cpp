class Solution {
  int backtrack(vector<vector<int>> &grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
      return 0;

    int gold = grid[i][j];
    grid[i][j] = 0;

    int maxGold = 0;
    maxGold = max(maxGold, backtrack(grid, i + 1, j));
    maxGold = max(maxGold, backtrack(grid, i - 1, j));
    maxGold = max(maxGold, backtrack(grid, i, j + 1));
    maxGold = max(maxGold, backtrack(grid, i, j - 1));

    grid[i][j] = gold;

    return gold + maxGold;
  }

public:
  int getMaximumGold(vector<vector<int>> &grid) {
    int maxTotal = 0;
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] > 0) {
          maxTotal = max(maxTotal, backtrack(grid, i, j));
        }
      }
    }

    return maxTotal;
  }
};
