#define ll long long
class Solution {
public:
  int md = 1e9 + 7;
  int lengthAfterTransformations(string s, int t, vector<int> &nums) {
    int n = s.size();
    vector<ll> FA(26);
    for (int i = 0; i < n; i++) {
      FA[s[i] - 'a']++;
    }

    vector<vector<int>> mat(26, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) {
      for (int j = 1; j <= nums[i]; j++) {
        mat[i][(i + j) % 26]++;
      }
    }

    auto newMat = binarypower(mat, t);
    vector<ll> newFA(26, 0);
    for (int i = 0; i < 26; i++) {
      if (FA[i] == 0)
        continue;
      for (int j = 0; j < 26; j++) {
        newFA[i] = (newFA[i] + (newMat[i][j] * FA[i]) % md) % md;
      }
    }
    ll res = 0;
    for (int i = 0; i < 26; i++) {
      res = (res + newFA[i]) % md;
    }
    return (int)res;
  }
  vector<vector<int>> binarypower(vector<vector<int>> mat, ll exp) {
    vector<vector<int>> res(26, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) {
      res[i][i] = 1;
    }
    while (exp > 0) {
      if (exp & 1) {
        res = matmul(res, mat);
      }
      mat = matmul(mat, mat);
      exp >>= 1;
    }
    return res;
  }
  vector<vector<int>> matmul(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<vector<int>> res(26, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        ll Aij = A[i][j];
        if (Aij == 0)
          continue;
        for (int k = 0; k < 26; k++) {
          res[i][k] = (res[i][k] + (Aij * B[j][k]) % md) % md;
        }
      }
    }
    return res;
  }
};