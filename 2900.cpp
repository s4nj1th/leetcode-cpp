class Solution {
public:
  vector<string> getLongestSubsequence(vector<string> &words,
                                       vector<int> &groups) {
    int n = words.size();

    int odd = 1;
    int eve = 0;

    vector<string> oArr;
    vector<string> eArr;

    int i = 0;
    while (i < n) {
      if (groups[i] == odd) {
        oArr.push_back(words[i]);
        odd = 1 - odd;
      }
      if (groups[i] == eve) {
        eArr.push_back(words[i]);
        eve = 1 - eve;
      }

      i++;
    }

    return (oArr.size() > eArr.size()) ? oArr : eArr;
  }
};