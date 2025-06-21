class Solution {
public:
  int minimumDeletions(string word, int k) {
    vector<int> freq(26, 0);

    for (char c : word)
      freq[c - 'a']++;

    vector<int> freqs;
    for (int f : freq)
      if (f > 0)
        freqs.push_back(f);

    sort(freqs.begin(), freqs.end());
    int ans = INT_MAX;
    int n = freqs.size();

    for (int i = 0; i < n; ++i) {
      int target = freqs[i];
      int deletions = 0;

      for (int f : freqs) {
        if (f < target) {
          deletions += f;
        } else if (f > target + k) {
          deletions += f - (target + k);
        }
      }

      ans = min(ans, deletions);
    }

    return ans;
  }
};
