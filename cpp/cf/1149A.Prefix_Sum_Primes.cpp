#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  int cnt1 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    cnt1 += x == 1 ? 1 : 0;
  }
  int cnt2 = n - cnt1;

  if (!cnt1 || !cnt2) {
    while (cnt1--) {
      std::cout << "1 ";
    }
    while (cnt2--) {
      std::cout << "2 ";
    }
    std::cout << '\n';
  } else {
    std::cout << "2 1 ";
    cnt1--, cnt2--;
    while (cnt2--) {
      std::cout << "2 ";
    }
    while (cnt1--) {
      std::cout << "1 ";
    }
    std::cout << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
