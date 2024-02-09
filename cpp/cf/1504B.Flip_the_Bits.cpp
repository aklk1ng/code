#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::string a, b;
  std::cin >> n;
  std::cin >> a >> b;
  a.push_back('0');
  b.push_back('0');
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += (a[i] == '1') - (a[i] == '0');
    if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && cnt) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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
