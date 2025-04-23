class Solution {
  int sumOfDig(int n) {
    int i = n;
    int sum = 0;
    while (i != 0) {
      sum += i % 10;
      i = i / 10;
    }

    return sum;
  }

public:
  int countLargestGroup(int n) {
    unordered_map<int, int> ht;
    int maxi = 0;
    int count = 0;

    for (int i = 1; i <= n; i++) {
      int x = sumOfDig(i);
      maxi = max(maxi, ++ht[x]);
    }
    for (auto &i : ht)
      if (i.second == maxi)
        ++count;
    return count;
  }
};