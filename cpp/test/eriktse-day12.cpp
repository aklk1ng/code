#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 1e2 + 5;

int a[N], dp1[N], dp2[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp1[i] = 1;
    for (int j = 1; j < i; j++) {
      if (a[j] <= a[i]) {
        dp1[i] = max(dp1[i], dp1[j] + 1);
      }
    }
  }

  for (int i = n; i >= 1; i--) {
    dp2[i] = 1;
    for (int j = n; j > i; j--) {
      if (a[j] <= a[i]) {
        dp2[i] = max(dp2[i], dp2[j] + 1);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp1[i] + dp2[i]);
  }
  cout << n - ans + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
