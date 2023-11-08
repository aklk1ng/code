#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  vector<int> a(3);
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  vector<int> p({0, 1, 2, 0, 2, 1, 0});
  int full = min({a[0] / 3, a[1] / 2, a[2] / 2});
  a[0] -= full * 3;
  a[1] -= full * 2;
  a[2] -= full * 2;

  int ans = 0;
  for (int i = 0; i < 7; i++) {
    int d = i;
    vector<int> b(a);
    int cur = 0;
    while (b[p[d]] > 0) {
      b[p[d]]--;
      d = (d + 1) % 7;
      cur++;
    }
    ans = max(ans, full * 7 + cur);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
