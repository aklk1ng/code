#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));

  if (n == 4) {
    cout << "4 6 8 1\n4 9 9 9\n4 10 10 65\n1 4 4 4\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    a[i][i] = 1;
    a[i][n - i - 1] = 1;
  }

  if (n % 2) {
    a[n / 2 + 1][n / 2] = 1;
    a[n / 2][n / 2 + 1] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " \n"[j == n - 1];
    }
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
