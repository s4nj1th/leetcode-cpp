class Solution {
public:
  int lenOfVDiagonal(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int memo[m][n][4][2];
    memset(memo, -1, sizeof(memo));

    function<int(int, int, int, bool, int)> dfs =
        [&](int cx, int cy, int dir, bool rotate, int key) -> int {
      int nx = cx + dirs[dir][0];
      int ny = cy + dirs[dir][1];

      if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != key) {
        return 0;
      }
      if (memo[nx][ny][dir][rotate] != -1) {
        return memo[nx][ny][dir][rotate];
      }

      int maxStep = dfs(nx, ny, dir, rotate, 2 - key);
      if (rotate) {
        maxStep = fmax(maxStep, dfs(nx, ny, (dir + 1) % 4, false, 2 - key));
      }
      memo[nx][ny][dir][rotate] = maxStep + 1;
      return maxStep + 1;
    };

    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          for (int dir = 0; dir < 4; ++dir) {
            res = fmax(res, dfs(i, j, dir, true, 2) + 1);
          }
        }
      }
    }

    return res;
  }
};