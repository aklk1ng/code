// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

// 求[1, n] 中因子数量为奇数的正整数的个数
void solve() {
  int n;
  std::cin >> n;
  while (n--) {
    int num;
    std::cin >> num;
    int cnt = 0;
    for (int i = 1; i <= num / i; i++)
      cnt++;
    std::cout << cnt << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
