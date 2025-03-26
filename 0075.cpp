class Solution {
public:
  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }
  void sortColors(vector<int> &nums) {
    int n = nums.size();
    int z = 0, t = n - 1, i = 0;

    while (i <= t) {
      if (nums[i] == 0) {
        swap(nums[i], nums[z]);
        z++;
        i++;
      } else if (nums[i] == 2) {
        swap(nums[i], nums[t]);
        t--;
      } else {
        i++;
      }
    }
  }
};