#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  string pi = "3141592653589793238462643383279";
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == pi[i]) {
      ans++;
    } else {
      break;
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
