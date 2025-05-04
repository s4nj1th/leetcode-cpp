class Solution {
public:
  int passThePillow(int n, int time) {
    n = n - 1;
    int turn = time / n;
    int rem = time % n;

    if (turn % 2 == 0) {
      return rem + 1;
    }

    return n - rem + 1;
  }
};