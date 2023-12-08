#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int M, D, y, m, d;
  cin >> M >> D;
  cin >> y >> m >> d;
  bool flag = ++d > D;
  if (flag) {
    flag = ++m > M;
    d = 1;
  }
  if (flag) {
    y++;
    m = 1;
  }
  cout << y << ' ' << m << ' ' << d;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
