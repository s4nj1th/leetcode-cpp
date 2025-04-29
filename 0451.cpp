class Solution {
public:
  string frequencySort(string s) {
    map<char, int> mp;
    string res = "";

    for (auto ch : s) {
      mp[ch]++;
    }

    vector<pair<char, int>> v;
    for (auto &it : mp) {
      v.push_back({it.first, it.second});
    }

    sort(v.begin(), v.end(),
         [](const pair<char, int> &a, const pair<char, int> &b) {
           return a.second > b.second;
         });

    string c;
    for (int i = 0; i < v.size(); i++) {
      while (v[i].second--) {
        c.push_back(v[i].first);
      }
    }

    return c;
  }
};