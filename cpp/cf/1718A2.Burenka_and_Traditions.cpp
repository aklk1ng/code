#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = n;
  for (int i = 1; i < n; i++) {
    a[i] ^= a[i - 1];
  }
  set<int> s;
  s.insert(0);
  for (auto &e : a) {
    if (s.count(e)) {
      ans -= 1;
      s.clear();
    }
    s.insert(e);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (true) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
