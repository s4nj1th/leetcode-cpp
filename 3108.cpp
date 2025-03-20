// using DFS (inefficient but cleaner)

class Solution {
//   int inf = 1e9;
  int getCompCost(int node, vector<vector<pair<int, int>>> &adjList,
                  vector<bool> &vis, vector<int> &comps, int compID) {
    int curCost = INT_MAX;

    comps[node] = compID;
    vis[node] = 1;

    for (auto &[v, w] : adjList[node]) {
      curCost &= w;

      if (!vis[v]) {
        curCost &= getCompCost(v, adjList, vis, comps, compID);
      }
    }

    return curCost;
  }

public:
  vector<int> minimumCost(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &queries) {
    vector<vector<pair<int, int>>> adjList(n);
    for (auto &i : edges) {
      // {u,  v,  w}
      // [0] [1] [2]
      adjList[i[0]].push_back({i[1], i[2]});
      adjList[i[1]].push_back({i[0], i[2]});
    }

    vector<bool> vis(n, 0);
    vector<int> comps(n, 0);
    vector<int> compCost;
    int compID = 0;

    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        compCost.push_back(getCompCost(i, adjList, vis, comps, compID));
        compID++;
      }
    }

    vector<int> res;

    for (auto &i : queries) {
      int source = i[0];
      int destn = i[1];

      if (comps[source] == comps[destn]) {
        res.push_back(compCost[comps[source]]);
      } else {
        res.push_back(-1);
      }
    }

    return res;
  }
};