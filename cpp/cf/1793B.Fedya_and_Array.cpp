#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll a, b;
  cin >> a >> b;
  ll n = 2 * (a - b);
  cout << n << '\n';
  vector<ll> arr(n);
  int ptr = 0;
  for (ll i = b; i <= a; i++) {
    arr[ptr++] = i;
  }
  for (ll i = a - 1; i > b; i--) {
    arr[ptr++] = i;
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " \n"[i == n - 1];
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
