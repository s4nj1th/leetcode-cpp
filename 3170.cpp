class Solution {
public:
  string clearStars(string s) {
    vector<char> ans(s.begin(), s.end());
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<>> heap;

    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];

      if (c == '*' && !heap.empty()) {
        auto [delChar, negIdx] = heap.top();
        heap.pop();
        int idx = -negIdx;
        ans[idx] = '#';
        ans[i] = '#';
      } else {
        heap.push({c, -i});
      }
    }

    string result;
    for (char c : ans) {
      if (c != '#')
        result += c;
    }

    return result;
  }
};
