class Solution {
public:
    string sortVowels(string s) {
        string vow;
        vector<int> idxs;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vow += s[i];
                idxs.push_back(i);
            }
        }

        sort(vow.begin(), vow.end());

        for (int i = 0; i < vow.size(); i++) {
            s[idxs[i]] = vow[i];
        }

        return s;
    }
};
