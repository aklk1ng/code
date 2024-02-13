#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> v;
  std::vector<int> a(n), b(n), c(n), ra(n + 1, 1), rb(n + 1, 1);
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
    v.push_back({c[i], i});
  }
  std::sort(v.rbegin(), v.rend());

  for (int i = 0; i < n; i++) {
    int k = v[i].second;
    if (ra[c[k]] == 1) {
      a[k] = c[k];
      ra[c[k]]--;
    } else {
      b[k] = c[k];
      rb[c[k]]--;
    }
  }

  int r1 = n, r2 = n;
  for (int i = 0; i < n; i++) {
    int k = v[i].second;
    if (!a[k]) {
      while (!ra[r1]) {
        r1--;
      }
      ra[r1]--;
      if (r1 > b[k]) {
        std::cout << "NO\n";
        return;
      }
      a[k] = r1--;
    } else {
      while (!rb[r2]) {
        r2--;
      }
      rb[r2]--;
      if (r2 > a[k]) {
        std::cout << "NO\n";
        return;
      }
      b[k] = r2--;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ra[i] || rb[i]) {
      std::cout << "NO\n";
      return;
    }
  }

  std::cout << "YES\n";
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; i++) {
    std::cout << b[i] << " \n"[i == n - 1];
  }
  return;
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
