#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  vector<vector<char>> grid(8, vector<char>(8));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < 8; i++) {
    bool line = true;
    if (grid[i][0] == 'R') {
      for (int j = 1; j < 8; j++) {
        if (grid[i][j] == 'B') {
          line = false;
          break;
        }
      }
      if (line) {
        cout << "R\n";
        return;
      }
    }
  }
  cout << "B\n";
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
