#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const ll N = 1e12 + 5;

unordered_set<ll> s;

void solve() {
  ll x;
  cin >> x;
  for (ll i = 1; i * i * i <= x; i++) {
    if (s.count(x - i * i * i)) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (ll i = 1; i * i * i <= N; i++) {
    s.insert(i * i * i);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
