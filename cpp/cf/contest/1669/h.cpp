#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> cnt(31), a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 30; j >= 0; j--) {
      if (a[i] & (1 << j)) {
        cnt[j]++;
      }
    }
  }
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int need = n - cnt[i];
    if (need <= k) {
      ans += (1 << i);
      k -= need;
    }
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
