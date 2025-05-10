class Solution {
public:
  long long minSum(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();

    long sum1 = 0;
    long sum2 = 0;
    long zero1 = 0;
    long zero2 = 0;

    for (int i = 0; i < n; i++) {
      if (nums1[i])
        sum1 += nums1[i];
      else {
        zero1++;
      }
    }

    for (int i = 0; i < m; i++) {
      if (nums2[i])
        sum2 += nums2[i];
      else {
        zero2++;
      }
    }

    if ((!zero1 && sum2 + zero2 > sum1 + zero1) ||
        (!zero2 && sum1 + zero1 > sum2 + zero2))
      return -1;

    return max(sum1 + zero1, sum2 + zero2);
  }
};