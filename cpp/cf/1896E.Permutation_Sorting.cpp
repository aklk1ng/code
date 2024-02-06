#include <bits/stdc++.h>
typedef long long ll;

int n;
std::vector<int> p, fw, ans;

void inc(int i, int x) {
  for (; i <= 2 * n; i += i & -i) {
    fw[i] += x;
  }
}

int qsm(int i) {
  int res = 0;
  for (; i > 0; i -= i & -i) {
    res += fw[i];
  }
  return res;
}

inline int qsm(int s, int e) { return qsm(e) - qsm(s - 1); }

void solve() {
  std::cin >> n;
  p.assign(n + 1, 0);
  fw.assign(2 * n + 5, 0);
  ans.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
  }
  std::vector<std::pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    if (i <= p[i]) {
      v.push_back({i, p[i]});
      v.push_back({i + n, p[i] + n});
    } else {
      v.push_back({i, p[i] + n});
    }
  }
  std::sort(v.begin(), v.end(), std::greater<std::pair<int, int>>());
  for (auto &[l, r] : v) {
    if (l <= n) {
      ans[p[l]] = r - l - qsm(l, r);
    }
    inc(r, 1);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
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
