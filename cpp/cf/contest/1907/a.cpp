#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string s;
  cin >> s;
  for (int i = 1; i <= 8; i++) {
    if (char('0' + i) != s[1]) {
      cout << s[0] << i << '\n';
    }
  }
  for (int i = 0; i < 8; i++) {
    if (char('a' + i) != s[0]) {
      cout << char('a' + i) << s[1] << '\n';
    }
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
