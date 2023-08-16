// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

void solve() {
  int n;
  std::cin >> n;
  ll s = 0, sum = 0;
  int l = 0, r = 0;
  while (n--) {
    r++;
    int c;
    std::cin >> c;
    if (c == 1) {
      s = r - l;
      l = r;
    }
    sum += s;
  }
  std::cout << sum;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
