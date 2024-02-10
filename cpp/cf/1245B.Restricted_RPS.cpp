#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  int a, b, c;
  std::cin >> a >> b >> c;
  std::string s;
  std::cin >> s;

  std::vector<int> cnt(26);
  for (auto &e : s) {
    cnt[e - 'A']++;
  }

  int wins = std::min(a, cnt['S' - 'A']) + std::min(b, cnt['R' - 'A']) +
             std::min(c, cnt['P' - 'A']);
  if (2 * wins < n) {
    std::cout << "NO\n";
    return;
  }

  std::cout << "YES\n";
  std::string t;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S' && a) {
      t += 'R';
      a--;
    } else if (s[i] == 'R' && b) {
      t += 'P';
      b--;
    } else if (s[i] == 'P' && c) {
      t += 'S';
      c--;
    } else {
      t += '_';
    }
  }
  for (int i = 0; i < n; i++) {
    if (t[i] != '_') {
      continue;
    }
    if (a) {
      t[i] = 'R';
      a--;
    } else if (b) {
      t[i] = 'P';
      b--;
    } else if (c) {
      t[i] = 'S';
      c--;
    }
  }
  std::cout << t << '\n';
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
