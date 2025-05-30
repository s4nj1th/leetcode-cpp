class Solution {
public:
  int minimumArea(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    int minRow = n, minCol = m;
    int maxRow = -1, maxCol = -1;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          minRow = min(minRow, i);
          maxRow = max(maxRow, i);
          minCol = min(minCol, j);
          maxCol = max(maxCol, j);
        }
      }
    }

    if (maxRow == -1)
      return 0;

    return (maxRow - minRow + 1) * (maxCol - minCol + 1);
  }
};
