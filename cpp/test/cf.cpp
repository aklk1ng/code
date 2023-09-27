#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10;
#define ll long long
const int N = 2e5 + 10;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> res(n + 1, 1);
  n = unique(a.begin(), a.end()) - a.begin();
  a.resize(n);
  for (int i = 0; i < n; i++) {
    res[a[i]]++;
  }
  res[a[0]] -= 1;
  res[a[n - 1]] -= 1;
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    ans = min(ans, res[a[i]]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
