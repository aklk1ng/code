#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  int ans = 0;
  int plain = m, logo = 0;
  for (auto &c : s) {
    if (c == '1') {
      if (plain) {
        plain--;
      } else {
        logo++;
      }
    } else if (c == '2') {
      logo++;
    } else {
      ans = max(ans, logo);
      plain = m;
      logo = 0;
    }
  }
  ans = max(ans, logo);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
