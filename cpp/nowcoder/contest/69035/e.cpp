#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
 int n, m, p;
 cin >> n >> m >> p;
 int ans = 0;
 for (int i = m; i <= n; i++) {
   if ((i - m) % p == 0) {
     ans++;
   }
 }
 cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
