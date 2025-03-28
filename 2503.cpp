class Solution {
public:
  vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
    int m = grid.size(), n = grid[0].size();
    int k = queries.size();

    vector<pair<int, int>> sortQ;
    for (int i = 0; i < k; i++) {
      sortQ.push_back({queries[i], i});
    }
    sort(sortQ.begin(), sortQ.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({grid[0][0], 0});

    vector<int> res(k, 0);
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    visited[0][0] = true;

    int count = 0;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (auto [q, i] : sortQ) {
      while (!pq.empty() && pq.top().first < q) {
        auto [val, pos] = pq.top();
        pq.pop();

        int row = pos / n, col = pos % n;
        c++;

        for (auto &d : dir) {
          int nr = row + d[0], nc = col + d[1];
          if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
            visited[nr][nc] = true;
            pq.push({grid[nr][nc], nr * n + nc});
          }
        }
      }
      res[i] = c;
    }

    return res;
  }
};
