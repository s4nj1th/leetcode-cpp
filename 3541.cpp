class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> ht;

        for (char i : s) {
            ht[i]++;
        }

        int maxVow = 0;
        int maxCon = 0;

        for (auto& [x,y] : ht) {
            if (x == 'a' || x == 'e' ||  x == 'i' ||  x == 'o' ||  x == 'u') {
                maxVow = max(maxVow, y);
            } else {
                maxCon = max(maxCon, y);
            }
        }

        return maxVow + maxCon;
    }
};
