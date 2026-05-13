class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int i : nums) {
            if (map[i]) return true;
            map[i]++;
        }

        return false;
    }
};
