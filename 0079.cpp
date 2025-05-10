class Solution {
public:
  bool dfs(vector<vector<char>> &board, string &word, int i, int j, int idx) {
    if (idx == word.size())
      return true;
    int n = board.size();
    int m = board[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[idx])
      return false;

    char part = board[i][j];
    board[i][j] = '#';

    bool found = dfs(board, word, i + 1, j, idx + 1) ||
                 dfs(board, word, i - 1, j, idx + 1) ||
                 dfs(board, word, i, j + 1, idx + 1) ||
                 dfs(board, word, i, j - 1, idx + 1);

    board[i][j] = part;

    return found;
  }

  bool exist(vector<vector<char>> &board, string word) {
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dfs(board, word, i, j, 0))
          return true;
      }
    }

    return false;
  }
};
