#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  ll n, x;
  cin >> n >> x;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    char op;
    cin >> op;
    ll n;
    cin >> n;
    if (op == '+') {
      x += n;
    } else {
      if (x < n) {
        ans++;
      } else {
        x -= n;
      }
    }
  }
  cout << x << ' ' << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
