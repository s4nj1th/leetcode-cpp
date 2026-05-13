class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> ht = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (ht.count(c)) {
                if (!st.empty() && st.top() == ht[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
