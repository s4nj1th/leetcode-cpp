class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int totalTank = 0, currTank = 0;
    int startIndex = 0;

    for (int i = 0; i < n; i++) {
      int diff = gas[i] - cost[i];
      totalTank += diff;
      currTank += diff;

      if (currTank < 0) {
        startIndex = i + 1;
        currTank = 0;
      }
    }

    return (totalTank < 0) ? -1 : startIndex;
  }
};