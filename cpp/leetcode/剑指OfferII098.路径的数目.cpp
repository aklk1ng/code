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
  int uniquePaths(int m, int n) {
    int i, j;
    int f[110][110];
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= n; j++) {
        if (i == 1 && j == 1)
          f[i][j] = 1;
        else if (i == 1)
          f[i][j] = f[i][j - 1];
        else if (j == 1)
          f[i][j] = f[i - 1][j];
        else
          f[i][j] = f[i - 1][j] + f[i][j - 1];
      }
    }
    return f[m][n];
  }
};
