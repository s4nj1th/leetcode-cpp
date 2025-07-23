class Solution {
public:
  int maximumGain(string s, int x, int y) {
    int score = 0;
    char c1 = 'a';
    int c2 = 'b';
    int cnt1 = 0;
    int cnt2 = 0;

    if (x < y) {
      swap(x, y);
      c1 = 'b';
      c2 = 'a';
    }

    for (char i : s) {
      if (i == c1) {
        cnt1++;
      } else if (i == c2) {
        if (cnt1 > 0) {
          cnt1--;
          score += x;
        } else {
          cnt2++;
        }
      } else {
        score += min(cnt1, cnt2) * y;
        cnt1 = 0;
        cnt2 = 0;
      }
    }

    if (cnt1 != 0) {
      score += min(cnt1, cnt2) * y;
    }

    return score;
  }
};
