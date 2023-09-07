// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 2e5 + 5;
int a[N], n;

int check(int mid) {
  int res = 0, pre = -1e9;
  for (int i = 1; i <= n; i++) {
    if (a[i] - pre >= mid) {
      res++;
      pre = a[i];
    }
  }
  return res;
}

void solve() {
  int c;
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int l = 0, r = 1e9 + 10;
  while (l + 1 != r) {
    int mid = l + (r - l) / 2;
    if (check(mid) >= c)
      l = mid;
    else
      r = mid;
  }
  cout << l << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
