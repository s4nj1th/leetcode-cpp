class Solution {
public:
  int maxPointsInsideSquare(vector<vector<int>> &points, string s) {
    vector<vector<int>> charPoint(26);

    for (int i = 0; i < s.size(); i++) {
      int x = abs(points[i][0]);
      int y = abs(points[i][1]);

      int len = max(x, y);
      charPoint[s[i] - 'a'].push_back(len);
    }

    int maxLen = 1e9;
    int res = 0;

    for (auto &i : charPoint) {
      sort(i.begin(), i.end());
      if (i.size() >= 2) {
        maxLen = min(maxLen, i[1] - 1);
      }
    }

    for (auto &i : charPoint) {
      if (i.size() > 0 && i[0] <= maxLen)
        res++;
    }

    return res;
  }
};