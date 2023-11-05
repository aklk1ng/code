#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll b;
  cin >> b;
  for (int i = 1; i <= 15; i++) {
    ll x = 1;
    for (int j = 0; j < i; j++) { 
      x *= i;
    }
    if (x == b) {
      cout << i << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
