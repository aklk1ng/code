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

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (target > nums[mid])
        l = mid + 1;
      else if (target < nums[mid])
        r = mid - 1;
      else
        return mid;
    }
    return -1;
  }
};

class Solution2 {
public:
  int search(vector<int> &nums, int target) {
    int l = -1, r = nums.size();
    if (nums.size() == 0)
      return -1;
    while (l + 1 != r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < target)
        l = mid;
      else
        r = mid;
    }
    return nums[r] == target ? r : -1;
  }
};
