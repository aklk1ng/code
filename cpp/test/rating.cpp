#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e9 + 10;
#define ll long long
const int N = 1e7 + 10;

bool check(ll i) {
  int pre = -1;
  int cur = 0;
  while (i) {
    cur = i % 10;
    if (cur > pre) {
      pre = cur;
      i /= 10;
    } else {
      return false;
    }
  }
  return true;
}

void solve() {
  int k;
  cin >> k;
  int cnt = 0;
  for (ll i = 1; i <= inf; i++) {
    if (check(i)) {
      cnt++;
    }
    if (cnt == k) {
      cout << i << '\n';
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
