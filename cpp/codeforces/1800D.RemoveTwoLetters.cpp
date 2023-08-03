// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int ans = n - 1;
    int extra = 0;
    for (int i = 0; i < n - 2; i++) {
      if (s[i] == s[i + 2])
        extra++;
    }
    std::cout << ans - extra << std::endl;
  }
  return 0;
}
