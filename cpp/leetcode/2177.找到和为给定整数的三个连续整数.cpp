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
  vector<long long> sumOfThree(long long num) {
    if (num % 3)
      return {};
    long long i = (num - 3) / 3;
    return {i, i + 1, i + 2};
  }
};
