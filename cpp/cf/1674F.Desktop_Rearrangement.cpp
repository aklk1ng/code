#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> t(n);
  string s;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    sum += count(t[i].begin(), t[i].end(), '*');
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      s += t[i][j];
    }
  }
  int ans = count(s.begin(), s.begin() + sum, '.');
  int pos = sum;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int p = y * n + x;
    if (p < pos) {
      if (s[p] == '.') {
        ans--;
      } else {
        ans++;
      }
    }
    s[p] = (s[p] == '.' ? '*' : '.');
    if (s[p] == '*') {
      if (s[pos] == '.') {
        ans++;
      }
      pos++;
    } else {
      if (s[pos - 1] == '.') {
        ans--;
      }
      pos--;
    }
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
