class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int ops = 0;

        int m = grid.size();
        int n = grid[0].size();

        int rem = grid[0][0] % x;

        for (vector<int> i : grid) {
            for (int j : i) {
                arr.push_back(j);
                if (rem != (j % x)) return -1;
            }
        }

        sort(arr.begin(), arr.end());

        int finCom = arr[m*n/2];
        for (int i : arr) {
            ops += abs(finCom - i) / x;
        }

        return ops;
    }
};
