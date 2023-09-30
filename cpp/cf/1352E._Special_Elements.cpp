#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    int sum = 0;
    for (int r = l; r <= n; r++) {
      sum += a[r];
      if (l == r) {
        continue;
      }
      if (sum <= n) {
        ans += cnt[sum];
        cnt[sum] = 0;
      }
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
