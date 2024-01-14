#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), cnt(n + 1), ans(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    cnt[a[i]]++;
  }
  int t = -1;
  while (cnt[t + 1] == 1) {
    t++;
  }
  ans[0] = t == n - 1;
  int l = 0, r = n - 1;
  ans[n - 1] = cnt[0] > 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!ans[n - 1]) {
      break;
    }
    ans[i] = true;
    int nxt = n - i - 1;
    if (--cnt[nxt] == 0 && (a[l] == nxt || a[r] == nxt) && cnt[nxt + 1]) {
      if (a[l] == nxt) {
        l++;
      }
      if (a[r] == nxt) {
        r--;
      }
      continue;
    }
    break;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
