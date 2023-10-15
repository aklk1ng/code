#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll sum = 0;

  multiset<ll> all;
  multiset<ll> s;
  for (int i = 0; i < k; i++) {
    all.insert(a[i]);
    sum += a[i];
  }
  for (int i = k; i < m; i++) {
    auto it = all.end();
    it--;
    ll mx = *it;
    if (a[i] < mx) {
      s.insert(mx);
      all.erase(it);
      all.insert(a[i]);
      sum -= mx;
      sum += a[i];
    } else {
      s.insert(a[i]);
    }
  }
  cout << sum << ' ';

  for (int i = m; i < n; i++) {
    ll x = a[i - m];
    auto it = s.find(x);
    if (it == s.end()) {
      all.erase(all.find(x));
      sum -= x;
    } else {
      s.erase(it);
    }
    s.insert(a[i]);

    if ((int)all.size() < k) {
      int mi = *s.begin();
      all.insert(*s.begin());
      s.erase(s.begin());
      sum += mi;
    } else {
      auto it = all.end();
      it--;
      ll mx = *it;
      ll mi = *s.begin();
      if (mi < mx) {
        s.erase(s.begin());
        s.insert(mx);
        all.erase(it);
        all.insert(mi);
        sum -= mx;
        sum += mi;
      }
    }
    cout << sum << ' ';
  }
  cout << '\n';

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
