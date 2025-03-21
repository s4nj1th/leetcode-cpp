class Solution {
  bool dfs(int node, vector<int> &vis, stack<int> &st,
           vector<vector<int>> &adjList) {
    if (vis[node] == 1)
      return false;
    if (vis[node] == 2)
      return true;

    vis[node] = 1;

    for (int neighbor : adjList[node]) {
      if (!dfs(neighbor, vis, st, adjList)) {
        return false;
      }
    }

    vis[node] = 2;
    st.push(node);
    return true;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adjList(numCourses);
    for (auto &pre : prerequisites) {
      adjList[pre[1]].push_back(pre[0]);
    }

    vector<int> vis(numCourses, 0);
    stack<int> st;

    for (int i = 0; i < numCourses; i++) {
      if (vis[i] == 0) {
        if (!dfs(i, vis, st, adjList)) {
          return {};
        }
      }
    }

    vector<int> topo;
    while (!st.empty()) {
      topo.push_back(st.top());
      st.pop();
    }

    return topo;
  }
};
