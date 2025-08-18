class Solution {
private:
  vector<double> genOps(double a, double b) {
    return {a + b, a - b, b - a, a * b, (double)a / b, (double)b / a};
  }

  bool backtrack(vector<double> &list) {
    if (list.size() == 1)
      return abs(list[0] - 24) < epsilon;

    for (int i = 0; i < list.size(); i++) {
      for (int j = i + 1; j < list.size(); j++) {
        double a = list[i], b = list[j];
        vector<double> copyList;
        for (int k = 0; k < list.size(); k++) {
          if (k != i && k != j)
            copyList.push_back(list[k]);
        }

        vector<double> resOps = genOps(a, b);
        for (double x : resOps) {
          copyList.push_back(x);
          if (backtrack(copyList))
            return true;
          copyList.pop_back();
        }
      }
    }
    return false;
  }

public:
  const double epsilon = 1e-6;
  bool judgePoint24(vector<int> &cards) {
    vector<double> list(cards.begin(), cards.end());
    return backtrack(list);
  }
};