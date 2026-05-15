class Solution {
private:
    vector<vector<int>> ans;

    void backtrack(int i, int n, vector<int> arr, vector<int> nums) {
        if (i == n) {
            ans.push_back(arr);
            return;
        }

        backtrack(i+1, n, arr, nums);
        arr.push_back(nums[i]);
        backtrack(i+1, n, arr, nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums.size(), {}, nums);
        return ans;
    }
};
