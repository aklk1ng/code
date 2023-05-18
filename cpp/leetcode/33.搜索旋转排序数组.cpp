#include <algorithm>
#include <cmath>
#include <deque>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Soluton {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target)
        return mid;
      // 左区间有序
      if (nums[l] <= nums[mid]) {
        if (nums[l] <= target && target <= nums[mid])
          r = mid - 1;
        else
          l = mid + 1;
      } else {
        // 右区间有序
        if (nums[mid] <= target && target <= nums[r])
          l = mid + 1;
        else
          r = mid - 1;
      }
    }
    return -1;
  }
};
