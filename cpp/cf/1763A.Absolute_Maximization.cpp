#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  int mx = 0, mi = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mx = (i == 0 ? x : mx | x);
    mi = (i == 0 ? x : mi & x);
  }
  cout << mx -  mi << '\n';
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
