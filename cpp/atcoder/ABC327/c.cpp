#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  vector<vector<int>> grid(9, vector<int>(9));
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> grid[i][j];
    }
  }
  vector<int> vis(9);
  bool ok = true;
  for (int i = 0; i < 9; i++) {
    fill(vis.begin(), vis.end(), 0);
    for (int j = 0; j < 9; j++) {
      vis[grid[i][j] - 1]++;
    }
    for (int k = 0; k < 9; k++) {
      if (vis[k] != 1) {
        ok = false;
      }
    }
  }

  for (int j = 0; j < 9; j++) {
    fill(vis.begin(), vis.end(), 0);
    for (int i = 0; i < 9; i++) {
      vis[grid[i][j] - 1]++;
    }
    for (int k = 0; k < 9; k++) {
      if (vis[k] != 1) {
        ok = false;
      }
    }
  }

  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      fill(vis.begin(), vis.end(), 0);
      for (int ii = 0; ii < 3; ii++) {
        for (int jj = 0; jj < 3; jj++) {
          vis[grid[i + ii][j + jj] - 1]++;
        }
      }
      for (int k = 0; k < 9; k++) {
        if (vis[k] != 1) {
          ok = false;
        }
      }
    }
  }

  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
