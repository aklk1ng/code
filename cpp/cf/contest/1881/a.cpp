#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, m;
  cin >> n >> m;
  string x;
  cin >> x;
  string s;
  cin >> s;
  int ans = 0;
  while (x.find(s) == string::npos) {
    if (ans >= 10) {
      cout << -1 << '\n';
      return;
    }
    x.append(x);
    ans++;
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
