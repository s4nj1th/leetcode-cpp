class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int x = 0, y = 0, diffX = 1, diffY = 0;
    vector<vector<int>> res(n, vector<int>(n, 0));

    for (int i = 0; i < n * n; i++) {
      res[y][x] = i + 1;

      if (!(0 <= x + diffX && x + diffX < n && 0 <= y + diffY &&
            y + diffY < n && res[y + diffY][x + diffX] == 0)) {
        int temp = diffX;
        diffX = -diffY;
        diffY = temp;
      }

      x += diffX;
      y += diffY;
    }

    return res;
  }
};