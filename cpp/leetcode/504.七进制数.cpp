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
  string convertToBase7(int num) {
    if (num == 0)
      return "0";
    string flag = "";
    if (num < 0) {
      flag = "-";
      num = -num;
    }
    string res;
    while (num) {
      res += num % 7 + '0';
      num /= 7;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
