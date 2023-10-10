#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (equal(a.begin() + 1, a.end(), a.begin())) {
    cout << -1 << '\n';
  } else {
    int mi = *min_element(a.begin(), a.end());
    sort(a.begin(), a.end());
    int ans = 0;
    for (auto &i : a) {
      ans = gcd(ans, i - mi);
    }
    cout << ans << '\n';
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
