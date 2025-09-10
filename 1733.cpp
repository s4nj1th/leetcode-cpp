class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>> &languages,
                       vector<vector<int>> &friendships) {
    unordered_set<int> usersToTeach;

    for (auto &i : friendships) {
      int u1 = i[0] - 1;
      int u2 = i[1] - 1;

      bool canTalk = false;

      for (int j : languages[u1]) {
        for (int k : languages[u2]) {
          if (j == k) {
            canTalk = true;
            break;
          }
        }

        if (canTalk)
          break;
      }

      if (!canTalk) {
        usersToTeach.insert(u1);
        usersToTeach.insert(u2);
      }
    }

    int minUsers = languages.size() + 1;

    for (int i = 1; i <= n; i++) {
      int ans = 0;

      for (int u : usersToTeach) {
        bool knows = false;
        for (int j : languages[u]) {
          if (j == i) {
            knows = true;
            break;
          }
        }

        if (!knows)
          ans++;
      }

      minUsers = min(minUsers, ans);
    }

    return minUsers;
  }
};