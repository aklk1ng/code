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

class MovingAverage {
public:
  vector<int> arr;
  int idx;
  int s, sum;
  MovingAverage(int size) {
    s = size;
    sum = 0;
    idx = 0;
  }
  double next(int val) {
    arr.push_back(val);
    sum += val;
    if (arr.size() > s)
      sum -= arr[idx++];

    return sum * 1.0 / (arr.size() - idx);
  }
};
