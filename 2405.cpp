class Solution {
public:
  int partitionString(string s) {
    int n = s.size();
    vector<int> charArr(26, 0);
    int i = 0;
    int count = 1;
    while (i < n) {
      if (charArr[s[i] - 'a'] == 1) {
        count++;
        fill(charArr.begin(), charArr.end(), 0);
      }
      charArr[s[i] - 'a'] = 1;
      i++;
    }

    return count;
  }
};