// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++)
    std::cin >> arr[i];
  int res = 0;
  for (int i = 0; i + 2 < n; i++) {
    res = std::max(res, arr[i] + arr[i + 2]);
  }
  std::cout << res << std::endl;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
