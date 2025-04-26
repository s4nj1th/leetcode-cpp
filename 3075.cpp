// priority queue
class Solution {
public:
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    long long dels = 0;
    long long sum = 0;

    priority_queue<int> pq(happiness.begin(), happiness.end());

    while (k != 0 && !pq.empty()) {
      if (pq.top() >= dels) {
        sum += pq.top() - dels;
        pq.pop();
        dels++;
        k--;
      } else {
        pq.pop();
      }
    }

    return sum;
  }
};

// simple sorting
class Solution {
public:
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    int n = happiness.size();
    int dels = 0;
    long long sum = 0;

    sort(happiness.begin(), happiness.end(), greater<int>());

    for (int i = 0; i < k; i++) {
      sum += (happiness[i] - dels > 0) ? happiness[i] - dels : 0;
      dels++;
    }

    return sum;
  }
};
