#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<int> fa(2 * n + 1);
  vector<int> fb(2 * n + 1);
  int p = 1;
  for (int i = 2; i <= n; i++) { 
    if (a[i] != a[i - 1]) { 
      fa[a[i - 1]] = max(fa[a[i - 1]], i - p);
      p = i;
    }
  }
  fa[a[n]] = max(fa[a[n]], n - p + 1);

  p = 1;
  for (int i = 2; i <= n; i++) { 
    if (b[i] != b[i - 1]) { 
      fb[b[i - 1]] = max(fb[b[i - 1]], i - p);
      p = i;
    }
  }
  fb[b[n]] = max(fb[b[n]], n - p + 1);

  int ans = 0;
  for (int i = 1; i <= 2 * n; i++) {
    ans = max(ans, fa[i] + fb[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
