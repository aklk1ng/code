#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::multiset<int> todo, done, e;
  for (int i = 0; i < m; i++) {
    int b;
    std::cin >> b;
    todo.insert(b);
  }

  for (int j = 0; j < m; j++) {
    if (todo.find(a[j]) != todo.end()) {
      todo.erase(todo.find(a[j]));
      done.insert(a[j]);
    } else {
      e.insert(a[j]);
    }
  }

  int ans = done.size() >= k;
  for (int i = m; i < n; i++) {
    int old = a[i - m];
    if (e.find(old) != e.end()) {
      e.erase(e.find(old));
    } else if (done.find(old) != done.end()) {
      done.erase(done.find(old));
      todo.insert(old);
    }
    if (todo.find(a[i]) != todo.end()) {
      todo.erase(todo.find(a[i]));
      done.insert(a[i]);
    } else {
      e.insert(a[i]);
    }
    ans += done.size() >= k;
  }
  std::cout << ans << '\n';
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
