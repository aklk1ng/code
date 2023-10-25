#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  string s = "989";
  if (n <= 3) {
    cout << s.substr(0, n) << '\n';
  } else {
    cout << s;
    for (int i = 3; i < n; i++) {
      cout << (i - 3) % 10;
    }
    cout << '\n';
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
