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
  char code(int n) {
    if (n >= 10)
      return n - 10 + 'a';
    return n + '0';
  }
  string toHex(int num) {
    unsigned int n = num;
    if (!n)
      return "0";
    string res;
    while (n) {
      res += code(n & 0xf);
      n >>= 4;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
