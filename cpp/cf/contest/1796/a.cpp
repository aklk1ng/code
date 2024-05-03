#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::string f;

void init() {
  int cur = 1;
  while (f.size() < 100) {
    if (cur % 3 == 0) {
      f += 'F';
    }
    if (cur % 5 == 0) {
      f += 'B';
    }
    cur++;
  }
}

void solve() {
  int k;
  std::cin >> k;
  std::string s;
  std::cin >> s;

  std::cout << (f.find(s) != std::string::npos ? "YES" : "NO") << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  init();
  while (T--) {
    solve();
  }

  return 0;
}
