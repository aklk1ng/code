// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e8;
#define ll long long
const int N = 1e5 + 5;
int a[N];

void solve() {
  int n, m, x;
  cin >> n >> m >> x;
  mt19937 rng(x);
  for (int i = 1; i <= n; i++) {
    a[i] = rng() % m;
  }
  map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      while (a[i]) {
        cnt[a[i] % 10]++;
        a[i] /= 10;
      }
    } else {
      cnt[a[i]]++;
    }
  }
  int ans = 0;
  int sum = 0;
  for (auto &[k, v] : cnt) {
    if (v > sum) {
      ans = k;
      sum = v;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
