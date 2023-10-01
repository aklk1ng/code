#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

int bit(int x) {
  int res = 0;
  while (x) {
    x /= 10;
    res++;
  }
  return (1 + res) * res / 2;
}

void solve() {
  int x;
  cin >> x;
  int rest = x % 10;
  int ans = 0;
  ans += (rest - 1) * 10;
  ans += bit(x);
  cout << ans << '\n';
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
