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

class RecentCounter {
public:
  queue<int> q;
  RecentCounter() {}
  int ping(int t) {
    while (!q.empty()) {
      if (t - q.front() > 3000)
        q.pop();
      else
        break;
    }
    q.push(t);
    return q.size();
  }
};
