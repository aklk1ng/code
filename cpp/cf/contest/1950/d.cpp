#include <bits/stdc++.h>
typedef long long ll;

std::vector<int> v;

void init() {
  for (int i = 2; i < 1e5 + 5; i++) {
    int cur = i;
    bool ok = false;
    while (cur) {
      if (cur % 10 > 1) {
        ok = true;
        break;
      }
      cur /= 10;
    }
    if (!ok) {
      v.push_back(i);
    }
  }
}

void solve() {
  int n;
  std::cin >> n;

  auto check = [&](auto self, int num) -> bool {
    if (num == 1) {
      return true;
    }
    bool ans = false;
    for (int &e : v) {
      if (num % e == 0) {
        ans |= self(self, num / e);
      }
    }
    return ans;
  };
  std::cout << (check(check, n) ? "YES" : "NO") << '\n';
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
