

using namespace std;

class Solution {
public:
  int minNumberDisappeared(vector<int> &nums) {
    int n = nums.size();
    // 将所有的负数修改为 n + 1
    for (int i = 0; i < n; i++) {
      if (nums[i] <= 0)
        nums[i] = n + 1;
    }
    // 每当遇到一个元素绝对值不超过n时，则表示这个元素是1～n中出现的元素
    // 我们可以将这个数值对应的下标里的元素改成负数
    // 相当于每个出现过的正整数，我们把与它值相等的下标都指向一个负数
    for (int i = 0; i < n; i++) {
      if (nums[i] <= n) {
        nums[abs(nums[i] - 1)] = -1 * abs(nums[abs(nums[i]) - 1]);
      }
    }
    // 最后遍历数组，寻找未被修改过的正数
    for (int i = 0; i < n; i++)
      if (nums[i] > 0)
        return i + 1;
    return n + 1;
  }
};
