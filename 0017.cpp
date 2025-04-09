class Solution {

  unordered_map<char, string> ht{{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                 {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                 {'8', "tuv"}, {'9', "wxyz"}};

  void backtrack(int i, string dig, string comb, vector<string> &res) {
    if (i == dig.size()) {
      res.push_back(comb);
      return;
    }

    string let = ht[dig[i]];
    for (char c : let) {
      backtrack(i + 1, dig, comb + c, res);
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;

    if (digits.size() == 0)
      return res;

    backtrack(0, digits, "", res);

    return res;
  }
};