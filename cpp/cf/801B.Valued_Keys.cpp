#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string x, z;
  cin >> x >> z;
  int n = x.size();
  for (int i = 0; i < n; i++) {
    if (z[i] > x[i]) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << z << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
