#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> arr(n);
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::vector<int> len(n), z(n);
  for (int i = 0; i < n; i++) {
    len[i] = arr[i].size();
    for (auto e = arr[i].rbegin(); e != arr[i].rend() && *e == '0'; e++) {
      z[i]++;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += len[i] - z[i];
  }
  std::sort(z.begin(), z.end());
  std::reverse(z.begin(), z.end());
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      ans += z[i];
    }
  }

  std::cout << (ans - 1 >= m ? "Sasha" : "Anna") << '\n';
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
