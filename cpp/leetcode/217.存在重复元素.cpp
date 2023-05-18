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
  bool containDuplicate(vector<int> &nums) {
    unordered_set<int> res;
    for (auto i : nums) {
      if (res.find(i) != res.end())
        return true;
      res.insert(i);
    }
    return false;
  }
};
