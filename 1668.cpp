#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxRepeating(string sequence, string word) {
    int gMax = 0;
    int N = sequence.size();
    int n = word.size();

    if (n == 0)
      return 0;

    for (int i = 0; i <= N - n; i++) {
      int c = 0;
      int j = i;

      while (j + n <= N && sequence.substr(j, n) == word) {
        c++;
        j += n;
      }

      gMax = max(gMax, c);
    }

    return gMax;
  }
};