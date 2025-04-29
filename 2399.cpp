class Solution {
public:
  bool checkDistances(string s, vector<int> &distance) {
    vector<int> firstIndex(26, -1);

    for (int i = 0; i < s.size(); ++i) {
      int idx = s[i] - 'a';

      if (firstIndex[idx] == -1) {
        firstIndex[idx] = i;
      } else {
        int gap = i - firstIndex[idx] - 1;
        if (gap != distance[idx])
          return false;
      }
    }

    return true;
  }
};
