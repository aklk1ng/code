#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];

    int r = 0, pos = 0;
    for (; pos < n; pos++) {
      if (s[r][pos] >= '3') {
        if (s[r ^ 1][pos] < '3') {
          break;
        } else {
          r ^= 1;
        }
      }
    }

    if (pos == n && r == 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
