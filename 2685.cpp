class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            UnionFind dsu(n);
            unordered_map<int, int> ec;
    
            for (const auto& e : edges) {
                dsu.unionSets(e[0], e[1]);
            }
    
            for (const auto& e : edges) {
                int r = dsu.find(e[0]);
                ec[r]++;
            }
    
            int cc = 0;
            for (int i = 0; i < n; i++) {
                if (dsu.find(i) == i) {
                    int nc = dsu.size[i];
                    int ee = (nc * (nc - 1)) / 2;
                    if (ec[i] == ee) {
                        cc++;
                    }
                }
            }
            return cc;
        }
    
    private:
        class UnionFind {
        public:
            vector<int> par;
            vector<int> size;
    
            UnionFind(int n) : par(n, -1), size(n, 1) {}
    
            int find(int u) {
                if (par[u] == -1) {
                    return u;
                }
                return par[u] = find(par[u]);
            }
    
            void unionSets(int u, int v) {
                int r1 = find(u);
                int r2 = find(v);
    
                if (r1 == r2) {
                    return;
                }
    
                if (size[r1] > size[r2]) {
                    par[r2] = r1;
                    size[r1] += size[r2];
                } else {
                    par[r1] = r2;
                    size[r2] += size[r1];
                }
            }
        };
    };