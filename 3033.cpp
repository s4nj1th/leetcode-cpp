class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        for (int i = 0; i < c; i++) {
            int maxE = -1;

            for (int j = 0; j < r; j++) {
                maxE = max(maxE, matrix[j][i]);
            }

            if (maxE == -1) continue;

            for (int j = 0; j < r; j++) {
                if (matrix[j][i] == -1) matrix[j][i] = maxE;
            }
        }

        return matrix;
    }
};
