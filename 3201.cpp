class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int odd = 0;
        int even = 0;
        int alter = 1;

        bool isOdd = nums[0] % 2;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2) odd++;
            else even++;

            if (nums[i] % 2 && !isOdd) {
                isOdd = !isOdd;
                alter++;
            } else if (!(nums[i] % 2) && isOdd) {
                isOdd = !isOdd;
                alter++;
            }
        }

        return max({odd, even, alter});
    }
};