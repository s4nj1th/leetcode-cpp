class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    int tot = m * n;

    vector<int> ans(tot);

    int i = 0;
    int j = 0;
    int k = 0;

    bool up = true;

    while (k < tot) {
      ans[k] = mat[i][j];

      if (up) {
        if (!i && j < n - 1) {
          j++;
          up = false;
        } else if (j == n - 1) {
          i++;
          up = false;
        } else {
          i--;
          j++;
        }
      } else {
        if (i < m - 1 && !j) {
          i++;
          up = true;
        } else if (i == m - 1) {
          j++;
          up = true;
        } else {
          i++;
          j--;
        }
      }

      k++;
    }

    return ans;
  }
};