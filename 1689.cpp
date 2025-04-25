class Solution {
public:
  int minPartitions(string n) {
    char maxChar = n[0];
    for (char c : n) {
      maxChar = max(maxChar, c);
    }

    return maxChar - '0';
  }
};