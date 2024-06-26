#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  int u = 0;
  for (int i = 0; i < n; i++) {
    bool fl = (a[i] == '1') && u;
    u ^= (a[i] - '0');
    if (i != 0) {
      cout << (fl ? '-' : '+');
    }
  }
  cout << '\n';
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
