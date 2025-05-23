class Solution {
public:
  long long maximumValueSum(vector<int> &nums, int k,
                            vector<vector<int>> &edges) {
    long long sum = 0;
    int count = 0, posMin = (1 << 30), negMax = -1 * (1 << 30);

    for (int nodeValue : nums) {
      int operatedNodeValue = nodeValue ^ k;
      sum += nodeValue;
      int netChange = operatedNodeValue - nodeValue;

      if (netChange > 0) {
        posMin = min(posMin, netChange);
        sum += netChange;
        count++;
      } else {
        negMax = max(negMax, netChange);
      }
    }

    if (count % 2 == 0) {
      return sum;
    }

    return max(sum - posMin, sum + negMax);
  }
};