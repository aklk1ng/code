#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  if (std::equal(s.begin() + 1, s.end(), s.begin())) {
    std::cout << n << '\n';
    return;
  }
  auto cal = [&](std::string &t) {
    int pos = t.find('R');
    ll res = 1LL * pos * (n - 1);
    int y = 0;
    for (int i = (int)t.size() - 1; i > pos - 1; i--) {
      if (t[i] == 'D') {
        res += y;
      } else {
        y++;
      }
    }
    return res;
  };

  ll ans = 1LL * n * n;
  ans -= cal(s);
  std::string tmp = "";
  for (auto &c : s) {
    if (c == 'D') {
      tmp += 'R';
    } else {
      tmp += 'D';
    }
  }
  ans -= cal(tmp);
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
