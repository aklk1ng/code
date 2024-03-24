#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, t;
  std::cin >> n >> t;

  std::vector<ll> scores(n);
  std::map<ll, int> m;
  m[0] = n;
  for (int i = 0; i < t; i++) {
    int a, b;
    std::cin >> a >> b;
    a--;
    if (--m[scores[a]] == 0) {
      m.erase(scores[a]);
    }
    scores[a] += b;
    m[scores[a]]++;
    std::cout << m.size() << '\n';
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
