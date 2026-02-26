class Solution {
public:
    int numSteps(string s) {
        int z = 1;
        int o = 0;
        int n = s.size();

        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '1') o++;
            if (o > 0 && s[i] == '0') z++;
        }

        return o == 1 ? n - 1 : z + n;
    }
};