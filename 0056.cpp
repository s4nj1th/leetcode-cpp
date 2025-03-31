class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> noOv;

    for (auto i : intervals) {
      if (noOv.empty() || noOv.back()[1] < i[0]) {
        noOv.push_back(i);
      } else {
        noOv.back()[1] = max(noOv.back()[1], i[1]);
      }
    }

    return noOv;
  }
};