#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  char cur = '1';
  int ans = 4;
  for (int i = 0; i < 4; i++) {
    if (s[i] == '0') {
      s[i] = '9' + 1;
    }
    ans += abs(s[i] - cur);
    cur = s[i];
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
