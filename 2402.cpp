class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    sort(meetings.begin(), meetings.end());

    priority_queue<int, vector<int>, greater<int>> available;
    for (int i = 0; i < n; ++i) {
      available.push(i);
    }

    using pii = pair<long long, int>;
    priority_queue<pii, vector<pii>, greater<pii>> occupied;

    vector<int> count(n, 0);

    for (const auto &m : meetings) {
      long long start = m[0], end = m[1];
      long long duration = end - start;

      while (!occupied.empty() && occupied.top().first <= start) {
        available.push(occupied.top().second);
        occupied.pop();
      }

      if (!available.empty()) {
        int room = available.top();
        available.pop();
        occupied.push({start + duration, room});
        count[room]++;
      } else {
        auto [freeTime, room] = occupied.top();
        occupied.pop();
        occupied.push({freeTime + duration, room});
        count[room]++;
      }
    }

    int maxCount = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (count[i] > maxCount) {
        maxCount = count[i];
        ans = i;
      }
    }
    return ans;
  }
};
