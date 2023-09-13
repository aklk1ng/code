// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  ll n;
  cin >> n;
  vector<ll> v;
  for (ll i = 2; i <= n / i; i++) {
    if (n % i)
      continue;
    v.push_back(i);
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n > 1) {
    v.push_back(n);
  }
  sort(v.begin(), v.end());
  for (auto &i : v) {
    cout << i << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int t;
  // cin >> t;
  // while (t--) {
  //   solve();
  // }
  solve();

  return 0;
}
