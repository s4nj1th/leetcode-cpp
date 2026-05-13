class Solution {
    private:
    void backtrack(int o, int c, int n, vector<string>& arr, string& st) {
        if (o == c && o == n) {
            arr.push_back(st);
            return;
        }

        if (o < n) {
            st += '(';
            backtrack(o+1, c, n, arr, st);
            st.pop_back();
        }

        if (c < o) {
            st += ')';
            backtrack(o, c+1, n, arr, st);
            st.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        string st;
        backtrack(0, 0, n, arr, st);
        return arr;
    }
};
