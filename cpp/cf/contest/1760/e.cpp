#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto calc = [&]() -> ll {
    ll res = 0, cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == 0) {
        cnt++;
      } else {
        res += cnt;
      }
    }
    return res;
  };
  ll ans = calc();
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      a[i] = 1;
      ans = max(ans, calc());
      a[i] = 0;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 1) {
      a[i] = 0;
      ans = max(ans, calc());
      a[i] = 1;
      break;
    }
  }
  cout << ans << '\n';
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
