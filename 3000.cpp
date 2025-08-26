class Solution {
  long long diag(vector<int> arr) { return arr[0] * arr[0] + arr[1] * arr[1]; }

  int areaFn(vector<int> arr) { return arr[0] * arr[1]; }

public:
  int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
    long long maxD = diag(dimensions[0]);
    int area = areaFn(dimensions[0]);

    for (auto i : dimensions) {
      if (maxD < diag(i)) {
        maxD = diag(i);
        area = areaFn(i);
      } else if (maxD == diag(i)) {
        area = max(area, areaFn(i));
      }
    }

    return area;
  }
};