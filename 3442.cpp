class Solution {
public:
  int maxDifference(string s) {
    // unordered_map<char, int> ht;
    vector<int> ht(26, 0);
    int maxOdd = 0;
    int minEve = 100;

    for (char c : s) {
      ht[c - 'a']++;
    }

    for (int i : ht) {
      if (i % 2)
        maxOdd = max(maxOdd, i);
      else
        minEve = (i != 0) ? min(minEve, i) : minEve;
    }

    return maxOdd - minEve;
  }
};