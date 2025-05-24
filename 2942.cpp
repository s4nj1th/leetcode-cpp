class Solution {
public:
  vector<int> findWordsContaining(vector<string> &words, char x) {
    int n = words.size();

    vector<int> idxs;

    for (int i = 0; i < n; i++) {
      for (char j : words[i]) {
        if (j == x) {
          idxs.push_back(i);
          break;
        }
      }
    }

    return idxs;
  }
};