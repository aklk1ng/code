// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
const int N = 30;
int n, k;
int a[N];

bool isprime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i <= n / i; i++)
    if (n % i == 0)
      return false;
  return true;
}
int dfs(int dep, int cnt, int sum) {
  if (cnt == k)
    return (int)isprime(sum);
  if (dep == n)
    return 0;

  int res = 0;
  res += dfs(dep + 1, cnt, sum);
  res += dfs(dep + 1, cnt + 1, sum + a[dep]);
  return res;
}
void solve() {
  std::cin >> n >> k;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  std::cout << dfs(0, 0, 0) << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
