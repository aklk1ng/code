#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> need(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i] / k;
    need[i] = a[i] % k;
  }
  sort(need.rbegin(), need.rend());
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    while (need[i] + need[j] < k && i < j) {
      j--;
    }
    if (i == j) {
      break;
    }
    ans++;
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
