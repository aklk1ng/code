#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[--p[i]] = i;
  }
  vector<bool> vis(n);
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }
    int t = pos[i];
    while (t < n) {
      vis[t] = 1;
      if (t + 1 == n) {
        break;
      }
      if (vis[t + 1]) {
        break;
      }
      if (p[t + 1] == p[t] + 1) {
        t++;
        continue;
      }
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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
