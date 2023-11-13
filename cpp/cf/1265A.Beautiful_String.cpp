#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string t = "abc";
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n - 1; i++) {
    if (isalpha(s[i]) && s[i] == s[i + 1]) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      if (i == 0) {
        s[i] = t[(s[i + 1] - 'a' + 1) % 3];
      } else if (i == n - 1) {
        s[i] = t[(s[i - 1] - 'a' + 1) % 3];
      } else {
        s[i] = t[(s[i - 1] - 'a' + 1) % 3];
        if (s[i] == s[i + 1]) {
          s[i] = t[(s[i] - 'a' + 1) % 3];
        }
      }
    }
  }
  cout << s << '\n';
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
