class Solution {
  long long genPal(int i, int half, int skip, int n) {
    long long base = pow(10, half - 1);
    long long prefix = base + i - 1;

    string s = to_string(prefix);
    string rev = s.substr(0, half - skip);
    reverse(rev.begin(), rev.end());
    s += rev;

    return stoll(s);
  }

public:
  vector<long long> kthPalindrome(vector<int> &queries, int intLength) {
    int half = intLength / 2;
    int skip = 0;

    if (intLength % 2) {
      half++;
      skip = 1;
    }

    vector<long long> pals;
    long long maxPal = pow(10, half) - pow(10, half - 1);

    for (int i : queries) {
      if (i > maxPal)
        pals.push_back(-1);
      else
        pals.push_back(genPal(i, half, skip, intLength));
    }

    return pals;
  }
};
