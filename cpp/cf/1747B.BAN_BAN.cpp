#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  cout << n / 2 + n % 2 << '\n';
  int l = 1, r = 3 * n;
  while (l < r) {
    cout << l << ' ' << r << '\n';
    l += 3;
    r -= 3;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
