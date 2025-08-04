/*
Qn
- fruits: arr
    - has type of fruit
- basket
    - at most 2 types of fruits
    - gotta pick the longest continous sub-arr with only 2 diff fruits
- op
    - most no of fruits can be picked
*/

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int n = fruits.size();
    unordered_map<int, int> ht;
    int l = 0, maxWindow = 0;

    for (int r = 0; r < n; r++) {
      ht[fruits[r]]++;

      while (ht.size() > 2) {
        ht[fruits[l]]--;

        if (ht[fruits[l]] == 0) {
          ht.erase(fruits[l]);
        }

        l++;
      }

      maxWindow = max(maxWindow, r - l + 1);
    }

    return maxWindow;
  }
};