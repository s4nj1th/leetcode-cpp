class Solution {
public:
  long long maxWeight(vector<int> &pizzas) {
    sort(pizzas.begin(), pizzas.end());

    int n = pizzas.size();
    int days = n / 4;
    int idx = n - 1;
    long long totalWeight = 0;

    for (int i = 1; i <= days; i += 2) {
      totalWeight += pizzas[idx--];
    }

    idx--;
    for (int i = 2; i <= days; i += 2) {
      totalWeight += pizzas[idx];
      idx -= 2;
    }

    return totalWeight;
  }
};