class Solution {
public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size();
    vector<int> idxs(n + 2, 0);
    vector<char> syms(n + 2, '.');

    int l = 1;
    idxs[0] = -1;
    syms[0] = 'L';

    for (int i = 0; i < n; i++) {
      if (dominoes[i] != '.') {
        idxs[l] = i;
        syms[l++] = dominoes[i];
      }
    }

    idxs[l] = n;
    syms[l++] = 'R';

    string res = dominoes;

    for (int idx = 0; idx < l - 1; idx++) {
      int i = idxs[idx];
      int j = idxs[idx + 1];

      char x = syms[idx];
      char y = syms[idx + 1];
      char write;

      if (x == y) {
        for (int k = i + 1; k < j; k++)
          res[k] = x;
      } else if (x > y) {
        for (int k = i + 1; k < j; k++)
          res[k] = (k - i == j - k) ? '.' : (k - i < j - k) ? 'R' : 'L';
      }
    }

    return res;
  }
};
