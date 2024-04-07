#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> c(n);
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
  }

  std::vector<int> lst(k, -1), mx1(k), mx2(k);
  for (int i = 0; i < n; i++) {
    int s = i - lst[c[i] - 1];
    if (s > mx1[c[i] - 1]) {
      mx2[c[i] - 1] = mx1[c[i] - 1];
      mx1[c[i] - 1] = s;
    } else if (s > mx2[c[i] - 1]) {
      mx2[c[i] - 1] = s;
    }
    lst[c[i] - 1] = i;
  }
  for (int i = 0; i < k; i++) {
    int s = n - lst[i];
    if (s > mx1[i]) {
      mx2[i] = mx1[i];
      mx1[i] = s;
    } else if (s > mx2[i]) {
      mx2[i] = s;
    }
  }

  int ans = 1e9;
  for (int i = 0; i < k; i++) {
    ans = std::min(ans, std::max((mx1[i] + 1) / 2, mx2[i]));
  }
  std::cout << ans - 1 << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
