class Solution {
public:
  long long minCost(vector<int> &basket1, vector<int> &basket2) {
    unordered_map<int, int> ht;
    vector<int> last;

    for (int i : basket1)
      ht[i]++;

    for (int i : basket2)
      ht[i]--;

    for (auto &i : ht) {
      if (i.second % 2)
        return -1;

      for (int j = 0; j < abs(i.second) / 2; j++) {
        last.push_back(i.first);
      }
    }

    int min1 = basket1[0];
    for (int i : basket1)
      min1 = min(min1, i);

    int min2 = basket2[0];
    for (int i : basket2)
      min2 = min(min2, i);

    int minI = min(min1, min2);

    sort(last.begin(), last.end());

    return accumulate(
        last.begin(), last.begin() + last.size() / 2, 0ll,
        [&](long long s, int x) -> long long { return s + min(2 * minI, x); });
  }
};