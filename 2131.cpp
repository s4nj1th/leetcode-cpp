class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> ht;
        int len = 0;
        bool mid = false;

        for (string& word : words) {
            ht[word]++;
        }

        for (auto& [word, freq] : ht) {
            string rev = string() + word[1] + word[0];
            if (word == rev) {
                len += (freq/2) * 4;
                if (freq % 2 == 1) mid = true;
            } else if (ht.find(rev) != ht.end()) {
                int pairs = min(freq, ht[rev]);
                len += pairs * 4;
                ht[rev] = 0;
            }
            ht[word] = 0; 
        }

        if (mid) len += 2;
        
        return len;
    }
};
