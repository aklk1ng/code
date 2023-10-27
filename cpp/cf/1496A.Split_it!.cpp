#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ok = 1;
  for (int i = 0; i < k; i++) {
    ok = ok && s[i] == s[n - i - 1];
  }
  cout << (ok && 2 * k < n ? "Yes" : "No") << '\n';
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
