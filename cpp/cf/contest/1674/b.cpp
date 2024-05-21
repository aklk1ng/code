#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  string s;
  cin >> s;
  if (s[0] < s[1]) {
    cout << 25 * (s[0] - 'a') + s[1] - 'a' << '\n';
  } else {
    cout << 25 * (s[0] - 'a') + s[1] - 'a' + 1 << '\n';
  }
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
