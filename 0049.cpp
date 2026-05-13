class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anaMap;
        for (string i : strs) {
            string j = i;
            sort(j.begin(), j.end());
            anaMap[j].push_back(i);
        }

        for (auto [x, y] : anaMap) {
            ans.push_back(y);
        }
        return ans;
    }
};
