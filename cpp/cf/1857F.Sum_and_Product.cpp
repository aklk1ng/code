#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  map<ll, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  auto my_sqrt = [&](ll a) {
    ll l = 0, r = 5e9 + 1;
    while (l + 1 != r) {
      ll mid = (l + r) / 2;
      if (1ll * mid * mid <= a) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  };
  auto cal = [&](int x, ll y) -> ll {
    ll d = 1LL * x * x - 4LL * y;
    if (d < 0) {
      return 0;
    }
    ll x1 = (x - my_sqrt(d)) / 2;
    ll x2 = (x + my_sqrt(d)) / 2;
    if (x1 + x2 != x || x1 * x2 != y) {
      return 0;
    }
    if (x1 == x2) {
      return 1LL * cnt[x1] * (cnt[x1] - 1) / 2LL;
    } else {
      return 1LL * cnt[x1] * cnt[x2];
    }
  };

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    ll y;
    cin >> x >> y;
    cout << cal(x, y) << " \n"[i == q - 1];
  }
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
