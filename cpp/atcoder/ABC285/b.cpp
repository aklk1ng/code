#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i < n; i++) {
    for (int l = 1; l <= n; l++) {
      if (i + l > n) {
        cout << l - 1 << '\n';
        break;
      } else if (s[l - 1] == s[i + l - 1]) {
        cout << l - 1 << '\n';
        break;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
