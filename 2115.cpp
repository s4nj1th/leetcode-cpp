class Solution {
public:
  vector<string> findAllRecipes(vector<string> &recipes,
                                vector<vector<string>> &ingredients,
                                vector<string> &supplies) {
    unordered_set<string> availSup;
    unordered_map<string, int> recToI;
    unordered_map<string, vector<string>> depGraph;

    for (string &i : supplies) {
      availSup.insert(i);
    }

    for (int i = 0; i < recipes.size(); i++) {
      recToI[recipes[i]] = i;
    }

    vector<int> inDeg(recipes.size(), 0);

    for (int i = 0; i < recipes.size(); i++) {
      for (string &ingredient : ingredients[i]) {
        if (!availSup.count(ingredient)) {
          depGraph[ingredient].push_back(recipes[i]);
          inDeg[i]++;
        }
      }
    }

    queue<int> q;
    for (int i = 0; i < recipes.size(); i++) {
      if (inDeg[i] == 0) {
        q.push(i);
      }
    }

    vector<string> pdts;
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      string rec = recipes[i];
      pdts.push_back(rec);

      if (!depGraph.count(rec))
        continue;

      for (string &j : depGraph[rec]) {
        if (--inDeg[recToI[j]] == 0) {
          q.push(recToI[j]);
        }
      }
    }

    return pdts;
  }
};