#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n;
  cin >> n;
  if (n > 3 && n % 3 == 0) {
    cout << 4 << '\n';
  } else {
    cout << 2 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
