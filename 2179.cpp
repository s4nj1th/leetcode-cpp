class fenTree {
private:
  vector<int> tree;

public:
  fenTree(int size) : tree(size + 1, 0) {}

  void update(int i, int delta) {
    i++;
    while (i < tree.size()) {
      tree[i] += delta;
      i += i & -i;
    }
  }

  int query(int i) {
    i++;
    int res = 0;
    while (i > 0) {
      res += tree[i];
      i -= i & -i;
    }
    return res;
  }
};

class Solution {
public:
  long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    vector<int> pos2(n), revIdxMap(n);
    for (int i = 0; i < n; i++) {
      pos2[nums2[i]] = i;
    }
    for (int i = 0; i < n; i++) {
      revIdxMap[pos2[nums1[i]]] = i;
    }
    fenTree tree(n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
      int pos = revIdxMap[i];
      int left = tree.query(pos);
      tree.update(pos, 1);
      int right = (n - 1 - pos) - (i - left);
      res += (long long)left * right;
    }
    return res;
  }
};