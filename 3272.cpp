class Solution {
public:
  long long countGoodIntegers(int n, int k) {
    unordered_set<string> ht;
    int base = pow(10, (n - 1) / 2);
    int skip = n & 1;
    for (int i = base; i < base * 10; i++) {
      string s = to_string(i);
      s += string(s.rbegin() + skip, s.rend());
      long long palInt = stoll(s);
      if (palInt % k == 0) {
        sort(s.begin(), s.end());
        ht.emplace(s);
      }
    }

    vector<long long> fact(n + 1, 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      fact[i] = fact[i - 1] * i;
    }
    for (const string &s : ht) {
      vector<int> count(10);
      for (char c : s) {
        count[c - '0']++;
      }
      long long tot = (n - count[0]) * fact[n - 1];
      for (int x : count) {
        tot /= fact[x];
      }
      ans += tot;
    }

    return ans;
  }
};