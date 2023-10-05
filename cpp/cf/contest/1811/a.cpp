#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] - '0' < d) {
      s.insert(i, to_string(d));
      cout << s << '\n';
      return;
    }
  }
  s.insert(n, to_string(d));
  cout << s << '\n';
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
