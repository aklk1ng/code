#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string s;
  std::cin >> s;

  int ans = 0;
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && s[j] != '1') {
      j++;
    }

    int l = s[i] == '1' ? k : 0;
    int r = j < n && s[j] == '1' ? k : 0;
    int len = j - i;
    if (l == k) {
      len--;
    }
    len -= l + r;
    if (len > 0) {
      ans += (len + k) / (k + 1);
    }
    i = j;
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
