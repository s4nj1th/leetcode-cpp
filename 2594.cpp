class Solution {
  long long countCar(long long time, vector<int> &ranks) {
    long long res = 0;
    for (int i : ranks) {
      res += sqrt(time / i);
    }
    return res;
  }

public:
  long long repairCars(vector<int> &ranks, int cars) {

    long long maxR = ranks[0];
    for (long long i : ranks) {
      if (i > maxR)
        maxR = i;
    }

    long long l = 1;
    long long r = maxR * cars * cars;
    long long res = r;

    while (l <= r) {
      long long mid = l + (r - l) / 2;
      long long rep = countCar(mid, ranks);
      if (rep >= cars) {
        res = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return res;
  }
};