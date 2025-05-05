class Solution {
public:
  bool canCompleteTrips(vector<int> &time, long long t, long long totalTrips) {
    long long trips = 0;
    for (int busTime : time) {
      trips += t / busTime;
      if (trips >= totalTrips)
        return true;
    }
    return trips >= totalTrips;
  }

  long long minimumTime(vector<int> &time, int totalTrips) {
    long long low = 1;
    long long high = 1LL * *min_element(time.begin(), time.end()) * totalTrips;

    while (low < high) {
      long long mid = (low + high) / 2;
      if (canCompleteTrips(time, mid, totalTrips)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};
