#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  int mx = 0, ans = 0;
  vector<int> cnt(N), f(N);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[f[x]]--;
    f[x]++;
    cnt[f[x]]++;
    mx = max(mx, f[x]);
    bool ok = false;
    if (cnt[1] == i) {
      ok = true;
    } else if (cnt[i] == 1) {
      ok = true;
    } else if (cnt[1] == 1 && cnt[mx] * mx == i - 1) {
      ok = true;
    } else if (cnt[mx - 1] * (mx - 1) == i - mx && cnt[mx] == 1) {
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
