class Solution {
public:
  int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                    int strength) {
    int n = tasks.size();
    int m = workers.size();
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    auto check = [&](int mid) -> bool {
      int p = pills;
      deque<int> ws;
      int ptr = m - 1;
      for (int i = mid - 1; i >= 0; --i) {
        while (ptr >= m - mid && workers[ptr] + strength >= tasks[i]) {
          ws.push_front(workers[ptr]);
          --ptr;
        }
        if (ws.empty()) {
          return false;
        } else if (ws.back() >= tasks[i]) {
          ws.pop_back();
        } else {
          if (!p) {
            return false;
          }
          --p;
          ws.pop_front();
        }
      }
      return true;
    };

    int l = 1;
    int r = min(m, n);
    int res = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        res = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return res;
  }
};