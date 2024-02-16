#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::vector<int> v(n + 1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      v[i + 1] = v[i] + 1;
    } else {
      v[i + 1] = v[i] - 1;
    }
  }

  if (v.back()) {
    std::cout << "-1\n";
    return;
  }

  if (*std::min_element(v.begin(), v.end()) == 0 ||
      *std::max_element(v.begin(), v.end()) == 0) {
    std::cout << "1\n";
    for (int i = 0; i < n; i++) {
      std::cout << 1 << " \n"[i == n - 1];
    }
    std::cout << '\n';
  } else {
    std::cout << "2\n";
    std::vector<int> ans;
    int cur = 0;
    while (cur < n) {
      int w = s[cur] == '(' ? 1 : 2;
      do {
        cur++;
        ans.push_back(w);
      } while (v[cur]);
    }
    for (int i = 0; i < n; i++) {
      std::cout << ans[i] << " \n"[i == n - 1];
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
