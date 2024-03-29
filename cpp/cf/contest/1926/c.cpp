#include <bits/stdc++.h>
typedef long long ll;

std::vector<int> res(2e5 + 5);

int cal(int num) {
  int ret = 0;
  while (num) {
    ret += num % 10;
    num /= 10;
  }
  return ret;
};

void init() {
  for (int i = 1; i < 2e5 + 5; i++) {
    res[i] = res[i - 1] + cal(i);
  }
}

void solve() {
  int n;
  std::cin >> n;

  std::cout << res[n] << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  init();
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
