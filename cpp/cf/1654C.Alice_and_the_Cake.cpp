#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll sum = accumulate(a.begin(), a.end(), 0LL);
  multiset<ll> p = {sum};
  multiset<ll> q(a.begin(), a.end());

  while (!q.empty()) {
    ll x = *--p.end();
    if (x < *--q.end()) {
      break;
    }
    p.erase(--p.end());
    if (q.find(x) != q.end()) {
      q.erase(q.find(x));
    } else {
      p.insert(x / 2);
      p.insert((x + 1) / 2);
    }
  }
  cout << (q.empty() ? "Yes" : "No") << '\n';
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
