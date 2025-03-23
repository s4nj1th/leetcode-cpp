class Solution {
public:
  int countPaths(int n, vector<vector<int>> &roads) {
    const int inf = 1e9 + 7;

    vector<vector<pair<int, int>>> graph(n);
    for (auto &road : roads) {
      int u = road[0], v = road[1], w = road[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<>>
        pq;

    vector<long long> minT(n, LLONG_MAX);
    vector<int> res(n, 0);

    minT[0] = 0;
    res[0] = 1;

    pq.emplace(0, 0);

    while (!pq.empty()) {
      long long t = pq.top().first;
      int u = pq.top().second;
      pq.pop();

      if (t > minT[u])
        continue;

      for (auto &[v, w] : graph[u]) {
        if (t + w < minT[v]) {
          minT[v] = t + w;
          res[v] = res[u];
          pq.emplace(minT[v], v);
        } else if (t + w == minT[v]) {
          res[v] = (res[v] + res[u]) % inf;
        }
      }
    }

    return res[n - 1];
  }
};