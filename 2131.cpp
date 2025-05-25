class Solution {
public:
  int longestPalindrome(vector<string> &words, int count = 0) {
    unordered_map<string, int> freq;
    int length = 0;
    bool hasCentral = false;

    for (const string &word : words) {
      freq[word]++;
    }

    for (auto &[word, count] : freq) {
      string rev = string(word.rbegin(), word.rend());

      if (word == rev) {
        int pairs = count / 2;
        length += pairs * 4;
        freq[word] -= pairs * 2;

        if (freq[word] > 0 && !hasCentral) {
          length += 2;
          hasCentral = true;
        }
      } else if (freq.find(rev) != freq.end()) {
        int pairs = min(freq[word], freq[rev]);
        length += pairs * 4;
        freq[word] -= pairs;
        freq[rev] -= pairs;
      }
    }

    return length;
  }
};