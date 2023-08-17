// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
const int N = 1e6 + 10;
int a[N];
int l[N]; // l[i]表示从i开始往左的连续0的个数
int r[N]; // l[i]表示从i开始往右的连续0的个数

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++)
    std::cin >> a[i];

  for (int i = 1; i <= n; i++) {
    if (a[i] == 1)
      continue;
    if (i > 1 && a[i - 1] == 0)
      l[i] = l[i - 1] + 1;
    else
      l[i] = 1;
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] == 1)
      continue;
    if (i < n && a[i + 1] == 0)
      r[i] = r[i + 1] + 1;
    else
      r[i] = 1;
  }
  long long ans = 0;

  for (int i = 1; i <= n; i++)
    if (a[i] == 1)
      ans += (l[i - 1] + 1) * (r[i + 1] + 1);
  std::cout << ans << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
