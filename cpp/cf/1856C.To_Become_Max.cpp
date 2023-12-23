#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll lb = 0, ub = *max_element(a.begin(), a.end()) + k, ans = 0;
  while (lb <= ub) {
    ll m = (lb + ub) / 2;
    bool ok = false;

    for (int i = 0; i < n; i++) {
      vector<ll> need(n);
      need[i] = m;
      ll used = 0;
      for (int j = i; j < n; j++) {
        if (need[j] <= a[j]) {
          break;
        }
        if (j + 1 >= n) {
          used = k + 1;
          break;
        }

        used += need[j] - a[j];
        need[j + 1] = max(0LL, need[j] - 1);
      }
      if (used <= k) {
        ok = true;
      }
    }
    if (ok) {
      ans = m;
      lb = m + 1;
    } else {
      ub = m - 1;
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
