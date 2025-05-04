class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int total = n + m;

    int mid1 = (total - 1) / 2;
    int mid2 = total / 2;

    int i = 0, j = 0;
    int count = 0;
    int current = 0, prev = 0;

    while (i < n || j < m) {
      prev = current;
      if (i < n && (j >= m || nums1[i] <= nums2[j])) {
        current = nums1[i++];
      } else {
        current = nums2[j++];
      }

      if (count == mid2) {
        return (total % 2 == 0) ? (prev + current) / 2.0 : current;
      }
      count++;
    }

    return 0.0;
  }
};
