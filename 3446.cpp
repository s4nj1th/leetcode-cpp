class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
    int n = grid.size();

    for (int i = 0; i < n; i++) {
      vector<int> diag;
      for (int j = 0; i + j < n; j++) {
        diag.push_back(grid[i + j][j]);
      }

      sort(diag.begin(), diag.end(), greater<int>());

      for (int j = 0; i + j < n; j++) {
        grid[i + j][j] = diag[j];
      }
    }

    for (int j = 1; j < n; j++) {
      vector<int> diag;
      for (int i = 0; j + i < n; i++) {
        diag.push_back(grid[i][j + i]);
      }

      sort(diag.begin(), diag.end());

      for (int i = 0; j + i < n; i++) {
        grid[i][j + i] = diag[i];
      }
    }
    return grid;
  }
};