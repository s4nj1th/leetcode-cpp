class Solution {
public:
  int maxDistance(string s, int k) {
    int n = s.size();
    int u = 0;
    int r = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      switch (s[i]) {
      case 'N':
        u++;
        break;
      case 'S':
        u--;
        break;
      case 'E':
        r++;
        break;
      case 'W':
        r--;
        break;
      }
      ans = max(ans, min(abs(u) + abs(r) + k * 2, i + 1));
    }
    return ans;
  }
};