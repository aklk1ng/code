#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int a, b;
  cin >> a >> b;
  cout << 2 << '\n';
  cout << a - 1 << ' ' << 1 << '\n';
  cout << a << ' ' << b << '\n';
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
