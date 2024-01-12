#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int lst = -n * m;
  vector<int> r(n * m), c(n * m);
  int col = 0;
  for (int i = 0; i < n * m; i++) {
    if (s[i] == '1') {
      lst = i;
      if (c[i % m] == 0) {
        c[i % m] = 1;
        col++;
      }
    }
    if (i - lst < m) {
      r[i % m]++;
    }
    if (i) {
      cout << ' ';
    }
    cout << r[i % m] + col;
  }
  cout << '\n';
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
