class Solution {
public:
  bool cuts(vector<vector<int>> &rects, int offset) {
    int n = rects.size();

    sort(rects.begin(), rects.end(),
         [&](const vector<int> &r1, const vector<int> &r2) {
           return r1[offset] < r2[offset];
         });

    int farEnd = rects[0][2 + offset];
    int gaps = 0;

    for (int i = 1; i < n; i++) {
      if (gaps >= 2)
        return true;

      if (rects[i][offset] >= farEnd)
        gaps++;

      farEnd = max(farEnd, rects[i][2 + offset]);
    }

    return gaps >= 2;
  }

  bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
    return cuts(rectangles, 0) || cuts(rectangles, 1);
  }
};