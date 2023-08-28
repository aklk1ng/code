// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
const int N = 1e4 + 5;
struct Node {
  int x1, y1, x2, y2;
} dp[N];

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b, g, k;
    std::cin >> a >> b >> g >> k;
    dp[i] = {a, b, a + g, b + k};
  }

  int x, y;
  std::cin >> x >> y;
  int ans = -1;
  for (int i = n; i >= 1; i--) {
    if (dp[i].x1 <= x && dp[i].x2 >= x && dp[i].y1 <= y && dp[i].y2 >= y) {
      ans = i;
      break;
    }
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
