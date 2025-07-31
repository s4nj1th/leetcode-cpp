class Solution {
public:
  int subarrayBitwiseORs(vector<int> &arr) {
    int n = arr.size();
    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
      int j = i - 1;
      int x = 0, y = arr[i];
      s.insert(y);

      for (int j = i - 1; j >= 0 && x != y; j--) {
        x |= arr[j];
        y |= arr[j];
        s.insert(y);
      }
    }

    return s.size();
  }
};