class Solution {
public:
  vector<string> findOcurrences(string text, string first, string second) {
    vector<string> res;
    string bigram = " " + first + " " + second + " ";
    string doneText = " " + text;
    auto p = doneText.find(bigram);
    while (p != string::npos) {
      auto p1 = p + bigram.size(), p2 = p1;
      while (p2 < doneText.size() && doneText[p2] != ' ')
        ++p2;
      res.push_back(doneText.substr(p1, p2 - p1));
      p = doneText.find(bigram, p + 1);
    }
    return res;
  }
};