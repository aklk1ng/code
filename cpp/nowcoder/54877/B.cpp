// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  std::string t;
  std::cin >> t;
  if (t.find("lov") < t.size() || t.find("ove") < t.size() || t.find("loe") < t.size() ||
      t.find("lve") < t.size())
    std::cout << "YES";
  else
    std::cout << "NO";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
