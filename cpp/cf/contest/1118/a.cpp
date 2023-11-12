#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (b >= 2 * a) {
    cout << n * a << '\n';
  } else {
    cout << n / 2 * b + n % 2 * a << '\n';
  }
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
