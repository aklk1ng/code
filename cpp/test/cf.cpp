#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10;
#define ll long long
const int N = 1e7 + 10;

bool dfs(int n, int m) {
  for (int i = 1; i <= n / 2; i++) {
    int j = 2 * i;
    if (i + j == n) {
      if (i == m || j == m) {
        return true;
      }
      return dfs(i, m) || dfs(j, m);
    }
  }
  return false;
}

void solve() {
  int n, m;
  cin >> n >> m;
  if (n == m) {
    cout << "Yes\n";
    return;
  }
  dfs(n, m) ? cout << "Yes\n" : cout << "No\n";
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
