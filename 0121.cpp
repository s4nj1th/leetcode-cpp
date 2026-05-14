class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices[0];
        int h = prices[0];
        int ans = 0;

        for (int i : prices) {
            if (i < l) {
                l = i;
                h = i;
            }
            if (i > h)
                h = i;

            ans = max(h-l, ans);
        }

        return ans;
    }
};
