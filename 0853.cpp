class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        stack<double> st;

        for (auto& i : cars) {
            double time = (double)(target - i.first) / i.second;

            st.push(time);

            if (st.size() >= 2) {
                double top = st.top();
                st.pop();

                if (top > st.top()) {
                    st.push(top);
                }
            }
        }

        return st.size();
    }
};
