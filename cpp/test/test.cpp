// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e8;
#define ll long long
const int N = 1e6 + 5;
int a[N];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = 1;
  for (; r <= n;) {
    if (a[r] >= 230) {
      if (r - l + 1 >= m) {
        cout << "Yes" << '\n';
        return;
      }
      r++;
    } else {
      r++;
      l = r;
    }
  }
  cout << "No" << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
