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
  int percentageLetter(string s, char letter) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == letter)
        cnt++;
    }
    return cnt * 100 / s.size();
  }
};
