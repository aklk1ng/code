#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  int Q;
  std::cin >> Q;

  std::string from, to;
  from = to = "abcdefghijklmnopqrstuvwxyz";

  while (Q--) {
    char c, d;
    std::cin >> c >> d;
    for (auto &&m : to) {
      if (m == c) {
        m = d;
      }
    }
  }

  for (const auto c : S) {
    for (int i = 0; i < 26; ++i) {
      if (c == from[i]) {
        std::cout << to[i];
      }
    }
  }
  std::cout << '\n';
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
