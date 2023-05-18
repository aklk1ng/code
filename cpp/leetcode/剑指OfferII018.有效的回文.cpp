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
  bool isPalindrome(string s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 'A' && s[i] <= 'Z')
        s[i] = s[i] - 'A' + 'a';
    }
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (!(s[l] >= 'a' && s[l] <= 'z' || s[l] >= '0' && s[l] <= '9')) {
        l++;
        continue;
      }
      if (!(s[r] >= 'a' && s[r] <= 'z' || s[r] >= '0' && s[r] <= '9')) {
        r--;
        continue;
      }
      if (s[l] != s[r])
        return false;
      l++;
      r--;
    }
    return true;
  }
};
