// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 1e5 + 5;
ll a[N], l[N], r[N], st[N], top;

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    while (top && a[st[top]] >= a[i])
      top--;
    if (top)
      l[i] = st[top];
    else
      l[i] = 0;
    st[++top] = i;
  }
  top = 0;
  for (int i = n; i >= 1; i--) {
    while (top && a[st[top]] > a[i])
      top--;
    if (top)
      r[i] = st[top];
    else
      r[i] = n + 1;
    st[++top] = i;
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i] * (i - l[i]) * (r[i] - i);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int t;
  // cin >> t;
  // while (t--) {
  //   solve();
  // }
  solve();

  return 0;
}
