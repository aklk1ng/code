#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 2e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      for (int j = i; j < n && j < i + k; j++) {
        s[j] = 'W';
      }
      ans++;
    }
  }
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
