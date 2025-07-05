class Solution {
public:
  int findLucky(vector<int> &arr) {
    vector<int> ht(501, 0);

    for (int i : arr) {
      ht[i]++;
    }

    for (int i = 500; i >= 1; i--) {
      if (ht[i] == i)
        return i;
    }

    return -1;
  }
};
