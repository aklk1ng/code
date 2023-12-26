#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  int cur = 0;
  vector<int> a(n), cnt(1e6 + 5);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = -1, r = -1, p = 0;
  for (int i = 0; i < n; i++) {
    while (p < n) {
      if (++cnt[a[p]] == 1) {
        cur++;
      }
      if (cur > k) {
        if (--cnt[a[p]] == 0) {
          cur--;
        }
        break;
      }
      p++;
    }
    if (r - l < p - i) {
      l = i;
      r = p;
    }
    if (--cnt[a[i]] == 0) {
      cur--;
    }
  }
  cout << l + 1 << ' ' << r << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
