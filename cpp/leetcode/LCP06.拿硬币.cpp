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
  int minCount(vector<int> &coins) {
    int s = 0;
    for (int i = 0; i < coins.size(); i++) {
      s += (coins[i] + 1) / 2;
    }
    return s;
  }
};
