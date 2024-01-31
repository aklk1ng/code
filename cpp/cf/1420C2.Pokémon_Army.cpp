#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

ll ans = 0;
int n, q;
std::vector<int> a;
void insert(int i) {
  if (i == 0 || i == n + 1) {
    return;
  }
  if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
    ans += a[i];
  }
  if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
    ans -= a[i];
  }
}

void erase(int i) {
  if (i == 0 || i == n + 1) {
    return;
  }
  if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
    ans -= a[i];
  }
  if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
    ans += a[i];
  }
}

void solve() {
  std::cin >> n >> q;
  a.resize(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  a[0] = -1;
  a[n + 1] = -1;
  ans = 0;

  for (int i = 1; i <= n; i++) {
    if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
      ans += a[i];
    }
    if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
      ans -= a[i];
    }
  }
  std::cout << ans << '\n';
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    erase(l - 1);
    erase(l);
    erase(l + 1);
    if (l != r) {
      if (r - 1 != l + 1 && r - 1 != l) {
        erase(r - 1);
      }
      if (r != l + 1) {
        erase(r);
      }
      erase(r + 1);
    }
    std::swap(a[l], a[r]);
    insert(l - 1);
    insert(l);
    insert(l + 1);
    if (l != r) {
      if (r - 1 != l + 1 && r - 1 != l) {
        insert(r - 1);
      }
      if (r != l + 1) {
        insert(r);
      }
      insert(r + 1);
    }
    std::cout << ans << '\n';
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
