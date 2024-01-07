#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }

  int cur = 0;
  map<int, int> m;
  m[0] = 0;
  for (int i = n; i < 2 * n; i++) {
    if (a[i] == 1) {
      cur++;
    } else {
      cur--;
    }
    if (!m.count(cur)) {
      m[cur] = i - (n - 1);
    }
  }

  int ans = 2 * n;
  int diff = count(a.begin(), a.end(), 1) - count(a.begin(), a.end(), 2);
  cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 1) {
      cur++;
    } else {
      cur--;
    }
    if (m.count(diff - cur)) {
      ans = min(ans, n - i + m[diff - cur]);
    }
  }
  if (m.count(diff)) {
    ans = min(ans, m[diff]);
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
