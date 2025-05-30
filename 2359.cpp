class Solution {
public:
  void getDistances(const vector<int> &edges, int startNode,
                    vector<int> &dist) {
    int n = edges.size();
    vector<bool> visited(n, false);
    int distance = 0;
    int current = startNode;

    while (current != -1 && !visited[current]) {
      dist[current] = distance;
      visited[current] = true;
      current = edges[current];
      distance++;
    }
  }

  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dist1(n, -1);
    vector<int> dist2(n, -1);

    getDistances(edges, node1, dist1);
    getDistances(edges, node2, dist2);

    int minDistance = INT_MAX;
    int answer = -1;

    for (int i = 0; i < n; ++i) {
      if (dist1[i] != -1 && dist2[i] != -1) {
        int maxDist = max(dist1[i], dist2[i]);
        if (maxDist < minDistance) {
          minDistance = maxDist;
          answer = i;
        }
      }
    }

    return answer;
  }
};
