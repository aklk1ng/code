#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    if (s[i] == '2') {
      a.push_back(i);
    }
  }
  int k = a.size();
  if (k == 1 || k == 2) {
    cout << "No\n";
    return;
  }
  vector<string> t(n, string(n, '='));
  for (int i = 0; i < n; i++) {
    t[i][i] = 'X';
  }
  for (int i = 0; i < k; i++) {
    int x = a[i], y = a[(i + 1) % k];
    t[x][y] = '+';
    t[y][x] = '-';
  }
  cout << "Yes\n";
  for (int i = 0; i < n; i++) {
    cout << t[i] << '\n';
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
