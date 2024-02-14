#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string s;
  std::cin >> s;

  int ones = 0, fst = n, lst = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] != '1') {
      continue;
    }
    ones++;
    if (fst == n) {
      fst = i;
    }
    lst = i;
  }
  int add = 0;
  if (ones > 0 && (n - 1 - lst) <= k) {
    k -= (n - 1 - lst);
    add++;
    ones--;
  }
  if (ones > 0 && fst <= k) {
    k -= fst;
    add += 10;
    ones--;
  }
  std::cout << 11 * ones + add << '\n';
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
