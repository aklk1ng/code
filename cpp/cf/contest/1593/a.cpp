#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  auto cal = [&](int vis, int x, int y) -> int { return max(0, max(x, y) + 1 - vis); };
  cout << cal(a, b, c) << ' ' << cal(b, a, c) << ' ' << cal(c, a, b) << '\n';
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
