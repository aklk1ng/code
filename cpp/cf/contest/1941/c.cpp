#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  std::vector<int> v;
  for (std::string sul : {"mapie", "pie", "map"}) {
    for (int i = 0; (i = s.find(sul, i)) != std::string::npos;) {
      s[i + sul.length() / 2] = '?';
      v.push_back(i + sul.length() / 2);
    }
  }
  std::cout << v.size() << '\n';
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
