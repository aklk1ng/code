#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n, x;
  cin >> n >> x;
  vector<vector<int>> tmp({
      {0, 1, 2},
      {1, 0, 2},
      {1, 2, 0},
      {2, 1, 0},
      {2, 0, 1},
      {0, 2, 1},
      {0, 1, 2}
  });
  cout << tmp[n % 6][x] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
