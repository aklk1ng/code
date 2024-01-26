#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;

bool check(std::vector<int> a, int k, int m) {
  int n = a.size();
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] * 2 < m) {
      a[i] = INF;
      k--;
      cur++;
    }
  }
  if (k < 0) {
    return false;
  }
  if ((k > 0 && cur > 0) || k >= 2) {
    return true;
  }
  if (k == 1 && !cur) {
    return *std::max_element(a.begin(), a.end()) >= m;
  }

  for (int i = 0; i < n - 1; i++) {
    if (std::min(a[i], a[i + 1]) >= m) {
      return true;
    }
  }
  return false;
};

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int l = 0, r = INF, tans = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(a, k, m)) {
      tans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  std::cout << tans << '\n';
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
