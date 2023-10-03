#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, m;
  cin >> n >> m;
  string black(m, 'B');
  vector<string> w(n, black);
  w[0][0] = 'W';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << w[i][j];
    }
    cout << '\n';
  }
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
