#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  partial_sum(a.begin(), a.end(), a.begin());
  if (k == 1) {
    ll ans = 0;
    map<ll, int> m;
    for (int i = n; i >= 0; i--) {
      if (m.find(a[i] + 1) != m.end()) {
        ans += m[a[i] + 1];
      }
      m[a[i]]++;
    }
    cout << ans << '\n';
  } else if (k == -1) {
    ll ans = 0;
    map<ll, int> m;
    for (int i = n; i >= 0; i--) {
      if (m.find(a[i] + 1) != m.end()) {
        ans += m[a[i] + 1];
      }
      if (m.find(a[i] - 1) != m.end()) {
        ans += m[a[i] - 1];
      }
      m[a[i]]++;
    }
    cout << ans << '\n';
  } else {
    ll ans = 0;
    map<ll, int> m;
    for (int i = n; i >= 0; i--) {
      ll cur = 1;
      while (true) {
        if (abs(cur) >= 1e15) {
          break;
        }
        if (m.find(a[i] + cur) != m.end()) {
          ans += m[a[i] + cur];
        }
        cur *= k;
      }
      m[a[i]]++;
    }
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
