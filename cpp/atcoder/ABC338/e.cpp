#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> v(2 * n);
  for (int i = 0; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    a--, b--;
    if (a > b) {
      std::swap(a, b);
    }
    v[a] = {0, i};
    v[b] = {1, i};
  }
  std::stack<int> st;
  for (int i = 0; i < 2 * n; i++) {
    auto [t, id] = v[i];
    if (!t) {
      st.push(id);
    } else {
      if (st.top() != id) {
        std::cout << "Yes\n";
        return;
      }
      st.pop();
    }
  }
  std::cout << "No\n";
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
