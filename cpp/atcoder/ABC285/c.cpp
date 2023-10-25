#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  ll ans = 0, add = 26;
  for (int i = 1; i <= n - 1; i++) {
    ans += add;
    add *= 26;
  }
  ll num = 0;
  for (int i = 0; i < n; i++) {
    num *= 26;
    num += (s[i] - 'A');
  }
  cout << ans + num + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
