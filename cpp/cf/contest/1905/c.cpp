#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  s = '$' + s;

  std::vector<int> v;
  for (int i = 1; i <= n; i++) {
    while (!v.empty() && s[v.back()] < s[i]) {
      v.pop_back();
    }
    v.push_back(i);
  }

  int ans = 0;
  int m = v.size() - 1;
  while (ans <= m && s[v[ans]] == s[v[0]]) {
    ans++;
  }
  ans = m - ans + 1;
  for (int i = 0; i <= m; i++) {
    if (i < m - i) {
      std::swap(s[v[i]], s[v[m - i]]);
    }
  }
  for (int i = 2; i <= n; i++) {
    if (s[i] < s[i - 1]) {
      ans = -1;
      break;
    }
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
