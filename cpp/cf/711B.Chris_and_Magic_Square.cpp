#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  int x, y;
  ll t1 = 0, t2 = 0;
  std::vector a(n, std::vector<int>(n));
  std::vector<ll> r(n), c(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
      if (!a[i][j]) {
        x = i, y = j;
      } else {
        r[i] += a[i][j];
        c[j] += a[i][j];
        if (i == j) {
          t1 += a[i][j];
        }
        if (i + j == n - 1) {
          t2 += a[i][j];
        }
      }
    }
  }

  if (n == 1) {
    std::cout << "1\n";
    return;
  }
  ll sum = r[0];
  if (!x) {
    sum = r[1];
  }
  ll rowsum = -1, colsum = -1, d1 = -1, d2 = -1;
  for (int i = 0; i < n; i++) {
    if (i != x) {
      if (r[i] != sum) {
        std::cout << "-1\n";
        return;
      }
    } else {
      rowsum = r[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (i != y) {
      if (c[i] != sum) {
        std::cout << "-1\n";
        return;
      }
    } else {
      colsum = c[i];
    }
  }

  bool ist1 = false, ist2 = false;
  if (x == y) {
    ist1 = true;
  }
  if (x + y == n - 1) {
    ist2 = true;
  }
  if (!ist1) {
    if (t1 != sum) {
      std::cout << "-1\n";
      return;
    }
  } else {
    d1 = t1;
  }
  if (!ist2) {
    if (t2 != sum) {
      std::cout << "-1\n";
      return;
    }
  } else {
    d2 = t2;
  }
  if (rowsum == colsum) {
    if ((ist1 && d1 != rowsum) || (ist2 && t2 != rowsum)) {
      std::cout << "-1\n";
      return;
    }
    ll val = sum - rowsum;
    if (val > 0) {
      std::cout << val << '\n';
    } else {
      std::cout << "-1\n";
      return;
    }
  } else {
    std::cout << "-1\n";
    return;
  }
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
