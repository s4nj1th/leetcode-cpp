class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> ht;
        int res = 0;

        for (int i : nums) {
            if (!ht[i]) {
                ht[i] = ht[i - 1] + ht[i + 1] + 1;
                ht[i - ht[i - 1]] = ht[i];
                ht[i + ht[i + 1]] = ht[i];
                res = (res > ht[i]) ? res : ht[i];
            }
        }

        return res;
    }
};
