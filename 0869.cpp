class Solution {
public:
  bool reorderedPowerOf2(int n) {
    string s = to_string(n);
    sort(s.begin(), s.end());

    for (int i = 0; i < 31; i++) {
      int m = (1 << i);
      string t = to_string(m);
      sort(t.begin(), t.end());
      if (t == s)
        return true;
    }

    return false;
  }
};