#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<ll> f(N), bitf(N);
  for (int j = 1; j <= n; j++) {
    for (int l = j + 1; l <= n; l++) {
      if (a[j] > a[l]) {
        f[j]++;
      }
    }
  }
  ll ans = 0;
  for (int k = 1; k <= n; k++) {
    for (int j = 1; j < k; j++) {
      if (a[j] > a[k]) {
        f[j]--;
      }
    }
    bitf[0] = 0;
    for (int i = 1; i <= k; i++) {
      bitf[i] = bitf[i - 1] + f[i];
    }
    for (int i = 1; i < k; i++) {
      if (a[i] < a[k]) {
        ans += bitf[k - 1] - bitf[i];
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
