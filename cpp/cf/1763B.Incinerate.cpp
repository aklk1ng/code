#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> m(n);
  for (int i = 0; i < n; i++) {
    cin >> m[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> m[i].second;
  }
  sort(m.begin(), m.end());
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    h[i] = m[i].first;
  }

  for (int i = n - 2; i >= 0; i--) {
    m[i].second = min(m[i + 1].second, m[i].second);
  }

  int base = 0;
  while (k > 0) {
    int ded = upper_bound(h.begin(), h.end(), k + base) - h.begin();
    if (ded == n) {
      cout << "Yes\n";
      return;
    }
    base += k;
    k -= m[ded].second;
  }

  cout << "No\n";
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
