#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += s[i] == '0';
  }
  if (cnt == 1) {
    std::cout << "BOB\n";
    return;
  }
  if (cnt % 2) {
    std::cout << "ALICE\n";
  } else {
    std::cout << "BOB\n";
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
