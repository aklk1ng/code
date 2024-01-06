#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const int mod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), cnt(N);
  cnt[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vector<int> cur;
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        cur.push_back(j);
        if (j != a[i] / j) {
          cur.push_back(a[i] / j);
        }
      }
    }
    sort(cur.begin(), cur.end());
    reverse(cur.begin(), cur.end());
    for (auto &e : cur) {
      cnt[e] += cnt[e - 1];
      cnt[e] %= mod;
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += cnt[i];
  }
  ans %= mod;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
