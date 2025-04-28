// char arr
class Solution {
public:
  int minimumLength(string s) {
    vector<int> charFreq(26, 0);
    int totalLength = 0;
    for (char i : s) {
      charFreq[i - 'a']++;
    }
    for (int frequency : charFreq) {
      if (frequency == 0)
        continue;
      if (frequency % 2 == 0) {
        totalLength += 2;
      } else {
        totalLength += 1;
      }
    }
    return totalLength;
  }
};

// char hashtable
class Solution {
public:
  int minimumLength(string s) {
    map<char, int> ht;
    int count = 0;

    for (char c : s) {
      ht[c]++;
    }

    for (auto &i : ht) {
      if (i.second % 2 == 0) {
        count += 2;
      } else {
        count += 1;
      }
    }

    return count;
  }
};
