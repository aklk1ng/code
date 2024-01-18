#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  vector<array<int, 2>> t({{-1, -1}});
  auto add = [&](int x) {
    int v = 0;
    for (int i = 19; i >= 0; i--) {
      int j = (x >> i) & 1;
      if (t[v][j] == -1) {
        t[v][j] = t.size();
        t.push_back({-1, -1});
      }
      v = t[v][j];
    }
  };
  for (auto &e : a) {
    add(e);
  }
  auto get = [&](int x) {
    int v = 0;
    for (int i = 19; i >= 0; i--) {
      int j = (x >> i) & 1;
      if (t[v][j ^ 1] != -1) {
        j ^= 1;
      }
      x ^= j << i;
      v = t[v][j];
    }
    return x;
  };

  for (int i = 0; i < n; i++) {
    if (get(i) == n - 1) {
      for (auto &e : a) {
        cout << (i ^ e) << ' ';
      }
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (false) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
