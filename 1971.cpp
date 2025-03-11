class Solution {
public:
  class DSU {
  public:
    vector<int> parent, rank;
    DSU(int n) {
      parent.resize(n);
      for (int i = 0; i < n; i++)
        parent[i] = i;
      rank.assign(n, 1);
    }

    int find(int i) {
      if (parent[i] != i)
        parent[i] = find(parent[i]);
      return parent[i];
    }

    void doUnion(int x, int y) {
      int pX = find(x), pY = find(y);

      if (rank[pX] > rank[pY]) {
        parent[pY] = pX;
      } else if (rank[pY] > rank[pX]) {
        parent[pX] = pY;
      } else {
        parent[pX] = pY;
        rank[pY]++;
      }
      return;
    }
  };

public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    DSU dsu(n);
    for (vector<int> edge : edges) {
      dsu.doUnion(edge[0], edge[1]);
    }
    return dsu.find(source) == dsu.find(destination);
  }
};