#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, s, k;
  cin >> n >> s >> k;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int p, q;
    cin >> p >> q;
    ans += p * q;
  }
  if (ans < s) {
    ans += k;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
