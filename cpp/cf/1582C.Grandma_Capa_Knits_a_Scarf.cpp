#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  string s;
  cin >> n >> s;
  int ans = n + 1;
  for (char c = 'a'; c <= 'z'; c++) {
    int l = 0, r = n - 1, cnt = 0;
    while (l <= r) {
      if (s[l] == s[r]) {
        l++, r--;
      } else if (s[l] == c) {
        l++, cnt++;
      } else if (s[r] == c) {
        r--, cnt++;
      } else {
        cnt = n + 1;
        break;
      }
    }
    ans = min(ans, cnt);
  }

  if (ans == n + 1) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
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
