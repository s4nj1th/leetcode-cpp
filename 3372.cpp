class Solution {
public:
  int dfs(int node, int parent, const vector<vector<int>> &children, int k) {
    if (k < 0) {
      return 0;
    }
    int res = 1;
    for (int i : children[node]) {
      if (i == parent) {
        continue;
      }
      res += dfs(i, node, children, k - 1);
    }
    return res;
  }

  vector<int> build(const vector<vector<int>> &edges, int k) {
    int n = edges.size() + 1;
    vector<vector<int>> children(n);
    for (const auto &i : edges) {
      children[i[0]].push_back(i[1]);
      children[i[1]].push_back(i[0]);
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = dfs(i, -1, children, k);
    }
    return res;
  }

  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2, int k) {
    int n = edges1.size() + 1, m = edges2.size() + 1;
    vector<int> count1 = build(edges1, k);
    vector<int> count2 = build(edges2, k - 1);
    int maxCount2 = *max_element(count2.begin(), count2.end());
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = count1[i] + maxCount2;
    }
    return res;
  }
};