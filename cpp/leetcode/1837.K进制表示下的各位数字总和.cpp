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
  int sumBase(int n, int k) {
    int res = 0;
    while (n) {
      res += n % k;
      n /= k;
    }
    return res;
  }
};
