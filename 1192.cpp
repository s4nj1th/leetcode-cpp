class Solution {
public:
  int time = 0;
  void findConns(int node, int parent, vector<vector<int>> &adj,
                 vector<int> &vis, vector<int> &entry, vector<int> &ancestor,
                 int n, vector<vector<int>> &ans) {
    entry[node] = ancestor[node] = time++;
    vis[node] = 1;
    for (auto it : adj[node]) {
      if (!vis[it]) {
        findConns(it, node, adj, vis, entry, ancestor, n, ans);
        ancestor[node] = min(ancestor[node], ancestor[it]);
        if (ancestor[it] > entry[node]) {
          ans.push_back({node, it});
        }
      } else if (it != parent) {
        ancestor[node] = min(ancestor[node], entry[it]);
      }
    }
  }
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    vector<vector<int>> adj;
    adj.resize(n + 1);
    int size = connections.size();
    for (int i = 0; i < size; i++) {
      int u = connections[i][0];
      int v = connections[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    vector<int> entry(n + 1, 0);
    vector<int> ancestor(n + 1, 0);
    vector<vector<int>> ans;
    findConns(0, -1, adj, vis, entry, ancestor, n, ans);
    return ans;
  }
};