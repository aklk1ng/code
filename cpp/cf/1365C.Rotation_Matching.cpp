#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  map<int, int> m;
  for (int i = 1; i <= n; i++) {
    int t = pos[b[i]] - i;
    if (t < 0) {
      t += n;
    }
    m[t]++;
  }

  int ans = 0;
  for (auto &e : m) {
    ans = max(ans, e.second);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  solve();

  return 0;
}
