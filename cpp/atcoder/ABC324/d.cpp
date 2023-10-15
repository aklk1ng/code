#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ranges::sort(s);

  int ans = 0;
  ll mx = pow(10, n);
  for (ll i = 0; i * i < mx; i++) {
    string t = to_string(i * i);
    t.resize(n, '0');

    ranges::sort(t);
    if (s == t) {
      ans++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
