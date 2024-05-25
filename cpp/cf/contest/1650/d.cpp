#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), ans(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  for (int i = n; i > 0; i--) {
    int ind = 0;
    for (int j = 0; j < i; j++) {
      ind = a[j] == i ? j : ind;
    }
    std::vector<int> b(i);
    for (int j = 0; j < i; j++) {
      b[(i - 1 - ind + j) % i] = a[j];
    }
    for (int j = 0; j < i; j++) {
      a[j] = b[j];
    }
    ans[i - 1] = i != 1 ? (ind + 1) % i : 0;
  }
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << " \n"[i == n - 1];
  }
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
