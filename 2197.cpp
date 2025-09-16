class Solution {
    int gcd(int x, int y) {
        while (y != 0) {
            int z = x % y;
            x = y;
            y = z;
        }
        return x;
    }

    int lcm(int x, int y) {
        return (1LL * x / gcd(x, y)) * y;
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        for (int i : nums) {
            s.push(i);

            while (s.size() > 1) {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                int g = gcd(a, b);

                if (g > 1) {
                    s.push(lcm(a, b));
                } else {
                    s.push(b);
                    s.push(a);
                    break;
                }
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
