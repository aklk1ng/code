#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + 5) < n) {
        int cnt = 0;
        for (int k = 0; k < 6; k++) {
          if (grid[i + k][j] == '#') {
            cnt++;
          }
        }
        if (cnt >= 4) {
          cout << "Yes\n";
          return;
        }
      }
      if ((j + 5) < n) {
        int cnt = 0;
        for (int k = 0; k < 6; k++) {
          if (grid[i][j + k] == '#') {
            cnt++;
          }
        }
        if (cnt >= 4) {
          cout << "Yes\n";
          return;
        }
      }
      if ((i + 5) < n && (j + 5) < n) {
        int cnt = 0;
        for (int k = 0; k < 6; k++) {
          if (grid[i + k][j + k] == '#') {
            cnt++;
          }
        }
        if (cnt >= 4) {
          cout << "Yes\n";
          return;
        }
      }
      if (0 <= (i - 5) && (j + 5) < n) {
        int cnt = 0;
        for (int k = 0; k < 6; k++) {
          if (grid[i - k][j + k] == '#') {
            cnt++;
          }
        }
        if (cnt >= 4) {
          cout << "Yes\n";
          return;
        }
      }
    }
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
