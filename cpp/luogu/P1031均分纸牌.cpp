// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  int avg = sum / n;

  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (avg > a[i]) {
      int k = avg - a[i];
      a[i + 1] -= k;
      a[i] += k;
      ans++;
    } else if (avg < a[i]) {
      int k = a[i] - avg;
      a[i] -= k;
      a[i + 1] += k;
      ans++;
    }
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
