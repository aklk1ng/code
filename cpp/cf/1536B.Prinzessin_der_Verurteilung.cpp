#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::set<std::string> se;
  for (int i = 0; i < n; i++) {
    std::string t;
    for (int k = 0; k < 5 && i + k < n; k++) {
      t.push_back(s[i + k]);
      se.insert(t);
    }
  }
  for (int i = 1; i < 6; i++) {
    std::string t(i, 'a');
    while (true) {
      if (se.count(t) == 0) {
        std::cout << t << '\n';
        return;
      }
      int idx = i - 1;
      while (idx >= 0 && t[idx] == 'z') {
        t[idx] = 'a';
        idx--;
      }
      if (idx < 0) {
        break;
      }
      t[idx]++;
    }
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
