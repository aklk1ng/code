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
  vector<int> runningsum(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
      nums[i] += nums[i - 1];
    }
    return nums;
  }
};
