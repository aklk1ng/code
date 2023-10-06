#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> perm(n, vector<int>(n - 1));
  vector<int> p(n);
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    p[i] = i + 1;
    for (int j = 0; j < n - 1; j++) {
      cin >> perm[i][j];
      if (j == 0) {
        cnt[perm[i][j]]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == n - 1) {
      p[0] = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (perm[i][0] != p[0]) {
      for (int j = 0; j < n - 1; j++) {
        p[j + 1] = perm[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << p[i] << " \n"[i == n - 1];
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
