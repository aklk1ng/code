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
  int kthFactor(int n, int k) {
    int sn = sqrt(n + 1e-7);
    int a[1001], top = 0;
    for (int i = 0; i <= sn; i++) {
      if (n % i == 0) {
        a[top++] = i;
        if (n / i != i)
          a[top++] = n / i;
      }
    }
    if (top < k)
      return -1;
    return a[k - 1];
  }
};
