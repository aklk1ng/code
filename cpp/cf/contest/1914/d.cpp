#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  auto cal = [](vector<int> t) -> tuple<int, int, int> {
    int mx1 = -1, mx2 = -1, mx3 = -1;
    for (int i = 0; i < (int)t.size(); i++) {
      if (mx1 == -1 || t[i] > t[mx1]) {
        mx3 = mx2;
        mx2 = mx1;
        mx1 = i;
      } else if (mx2 == -1 || t[i] > t[mx2]) {
        mx3 = mx2;
        mx2 = i;
      } else if (mx3 == -1 || t[i] > t[mx3]) {
        mx3 = i;
      }
    }
    return {mx1, mx2, mx3};
  };
  int ans = 0;
  auto [x1, y1, z1] = cal(a);
  auto [x2, y2, z2] = cal(b);
  auto [x3, y3, z3] = cal(c);
  for (auto &e1 : {x1, y1, z1}) {
    for (auto &e2 : {x2, y2, z2}) {
      for (auto &e3 : {x3, y3, z3}) {
        if (e1 != e2 && e1 != e3 && e2 != e3) {
          ans = max(ans, a[e1] + b[e2] + c[e3]);
        }
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
