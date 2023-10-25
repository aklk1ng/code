#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  ll sum = accumulate(a.begin(), a.end(), 0LL);
  if ((2 * sum) % n != 0) {
    cout << 0 << '\n';
  } else {
    ll need = (2 * sum) / n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int a1 = a[i];
      int a2 = need - a1;
      if (cnt.count(a2)) {
        ans += cnt[a2];
      }
      if (a1 == a2) {
        ans -= 1;
      }
    }
    cout << ans / 2 << '\n';
  }
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
