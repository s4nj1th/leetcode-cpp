class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, maxFreq = 0, ans = 0;
        vector<int> freq(26,0);

        for(int r = 0; r < s.size(); r++){
            freq[s[r]-'A']++;
            maxFreq = max(freq[s[r]-'A'], maxFreq);

            while((r-l+1) - maxFreq > k) {
                freq[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
