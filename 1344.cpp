class Solution {
public:
  double angleClock(int hour, int minutes) {
    return min(abs((30 * (double)hour) - (5.5 * (double)minutes)),
               360 - abs((30 * (double)hour) - (5.5 * (double)minutes)));
  }
};