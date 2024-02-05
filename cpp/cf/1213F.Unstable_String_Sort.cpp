#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> p1(n), p2(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p1[i];
    p1[i]--;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> p2[i];
    p2[i]--;
  }

  std::set<int> s1, s2;
  std::vector<int> rb;
  for (int i = 0; i < n; i++) {
    if (s2.count(p1[i])) {
      s2.erase(p1[i]);
    } else {
      s1.insert(p1[i]);
    }
    if (s1.count(p2[i])) {
      s1.erase(p2[i]);
    } else {
      s2.insert(p2[i]);
    }
    if (s1.empty() && s2.empty()) {
      rb.push_back(i);
    }
  }
  if ((int)rb.size() < k) {
    std::cout << "NO\n";
  } else {
    std::string s(n, ' ');
    int l = 0;
    for (int i = 0; i < (int)rb.size(); i++) {
      int r = rb[i];
      char c = 'a' + std::min(i, 25);
      for (int j = l; j <= r; j++) {
        s[p1[j]] = c;
      }
      l = r + 1;
    }
    std::cout << "YES\n" << s << '\n';
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
