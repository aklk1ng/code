#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), d(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    d[i]--;
  }

  vector<int> pa(n);
  vector<bool> done(n);
  for (int i = 0; i < n; i++) {
    pa[a[i]] = i;
  }
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    if (done[i]) {
      continue;
    }
    if (d[i] == -1) {
      continue;
    }
    for (int j = i; !done[j]; j = pa[b[j]]) {
      done[j] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (done[i]) {
      continue;
    }
    if (d[i] == -1 && a[i] != b[i]) {
      ans = (2 * ans) % mod;
    }
    for (int j = i; !done[j]; j = pa[b[j]]) {
      done[j] = true;
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
