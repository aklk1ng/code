#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  int x = 0, y = 0;
  int k = 1;
  int cur = 1;
  vector a(45, vector<int>(45));
  vector<int> dx{0, 0, -1, 1};
  vector<int> dy{1, -1, 0, 0};
  a[0][0] = 1;
  while (cur < n * n) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (0 <= xx && xx < n && 0 <= yy && yy < n && a[xx][yy] == 0) {
      a[xx][yy] = ++cur;
      x = xx;
      y = yy;
    } else {
      k = (k + 1) % 4;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == n * n) {
        cout << "T ";
      } else {
        cout << a[i][j] << ' ';
      }
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
