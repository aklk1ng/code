#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n / 2), p(n);
  vector<bool> used(n + 1);
  set<int> unused;
  for (int i = 0; i < n / 2; i++) {
    cin >> b[i];
    p[i * 2 + 1] = b[i];
    used[b[i]] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      unused.insert(i);
    }
  }
  if ((int)unused.size() != n / 2) {
    cout << -1 << '\n';
    return;
  }

  for (int i = n / 2 - 1; i >= 0; i--) {
    auto k = unused.upper_bound(p[2 * i + 1]);
    if (k == unused.begin()) {
      cout << -1 << '\n';
      return;
    }
    k--;
    if (*k < p[2 * i + 1]) {
      p[2 * i] = *k;
      unused.erase(k);
    } else {
      cout << -1 << '\n';
      return;
    }
  }
  for (auto &e : p) {
    cout << e << " \n"[e == p.back()];
  }
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
