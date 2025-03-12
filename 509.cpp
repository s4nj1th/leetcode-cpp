class Solution {
public:
  int fib(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;

    vector<int> fibV = {0, 1};
    for (int i = 2; i < n + 1; i++)
      fibV.push_back(fibV[i - 1] + fibV[i - 2]);

    return fibV[n];
  }
};