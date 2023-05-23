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
  int gcd(int a, int b) {
    for (int i = a; i >= 1; i--) {
      if (a % i == 0 && b % i == 0)
        return i;
    }
    return 1;
  }
  int findGCD(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int min = nums[0];
    int max = nums[nums.size() - 1];
    return gcd(min, max);
  }
};
