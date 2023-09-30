#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

int bit(string s) {
  int res = -1;
  for (int i = 0; i < (int)s.size(); i++) {
    if ((int)s[i] % 2 == 0) {
      return i;
    }
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << 0 << '\n';
  } else {
    int pos = bit(to_string(n));
    if (pos == 0) {
      cout << 1 << '\n';
    } else if (pos > 0 && pos < n - 1) {
      cout << 2 << '\n';
    } else {
      cout << -1 << '\n';
    }
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
