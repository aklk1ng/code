#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), f(N), cnt(N);
  int mx = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[f[a[i]]]--;
    f[a[i]]++;
    cnt[f[a[i]]]++;
    mx = max(mx, f[a[i]]);
    bool ok = false;
    if (cnt[1] == i || cnt[i] == 1 || (cnt[1] == 1 && cnt[mx] * mx == i - 1) ||
        (cnt[mx - 1] * (mx - 1) == i - mx && cnt[mx] == 1)) {
      ok = true;
    }
    if (ok) {
      ans = i;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
