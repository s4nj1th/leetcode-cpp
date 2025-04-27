class Solution {
public:
  int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
    int n = aliceValues.size();
    vector<pair<int, int>> stones;

    for (int i = 0; i < n; i++) {
      stones.push_back({aliceValues[i] + bobValues[i], i});
    }

    sort(stones.rbegin(), stones.rend());

    int alice = 0, bob = 0;

    for (int i = 0; i < n; i++) {
      int j = stones[i].second;
      if (i % 2 == 0) {
        alice += aliceValues[j];
      } else {
        bob += bobValues[j];
      }
    }

    if (alice > bob)
      return 1;
    if (alice < bob)
      return -1;
    return 0;
  }
};
