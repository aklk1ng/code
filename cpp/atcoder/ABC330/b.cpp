#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (a[i] <= l) {
      ans[i] = l;
    } else if (a[i] >= r) {
      ans[i] = r;
    } else {
      ans[i] = a[i];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
