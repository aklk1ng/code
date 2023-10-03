#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<string> p[3];
  for (int i = 0; i < 3; i++) {
    p[i].resize(n);
  }
  map<string, int> m;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
      m[p[i][j]]++;
    }
  }
  for (int i = 0; i < 3; i++) {
    int sum = 0;
    for (auto &s : p[i]) {
      if (m[s] == 1) {
        sum += 3;
      } else if (m[s] == 2) {
        sum += 1;
      }
    }
    cout << sum << " \n"[i == 2];
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
