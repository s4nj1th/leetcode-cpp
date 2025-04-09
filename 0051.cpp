class Solution {
  bool isSafe(vector<string> &board, int r, int c, int n) {
    for (int i = 0; i < r; i++)
      if (board[i][c] == 'Q')
        return false;

    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
      if (board[i][j] == 'Q')
        return false;

    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
      if (board[i][j] == 'Q')
        return false;

    return true;
  }

  void solve(int r, vector<string> &board, vector<vector<string>> &res, int n) {
    if (r == n) {
      res.push_back(board);
      return;
    }

    for (int i = 0; i < n; i++) {
      if (isSafe(board, r, i, n)) {
        board[r][i] = 'Q';
        solve(r + 1, board, res, n);
        board[r][i] = '.';
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    solve(0, board, res, n);
    return res;
  }
};