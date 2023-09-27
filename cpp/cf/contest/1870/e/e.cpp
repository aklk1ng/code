#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 2e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<ll> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] ^ a[i];
  }
  int q;
  cin >> q;
  while (q--) {
    ll l, k;
    cin >> l >> k;
    ll r = n + 1;
    while (l + 1 != r) {
      ll mid = l + (r - l) / 2;
      if ((pre[mid] ^ pre[l - 1]) >= k) {
        l = mid;
      } else {
        r = mid;
      }
    }

    cout << ((pre[r] ^ pre[l - 1]) >= k ? l : -1) << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
