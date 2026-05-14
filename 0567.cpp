class Solution {
    bool equalFreq(vector<int> a, vector<int> b){
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        vector<int> ht1(26, 0);
        for(char c: s1) ht1[c - 'a']++;

        vector<int> ht2(26, 0);
        int i = 0, j = 0;

        while (j < s2.size()) {
            ht2[s2[j] - 'a']++;

            if (j - i + 1 == s1.size()) {
                if (equalFreq(ht1, ht2)) return true;
            }

            if (j - i + 1 < s1.size()) j++;
            else {
                ht2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }

        return false;
    }
};
