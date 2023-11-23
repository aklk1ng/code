#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt0 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!a[i]) {
      cnt0++;
    }
  }
  int cnt1 = n - cnt0;
  if (cnt0 >= n / 2) {
    cout << cnt0 << '\n';
    for (int i = 0; i < cnt0; i++) {
      cout << 0 << " \n"[i == cnt0 - 1];
    }
  } else {
    int cnt = cnt1 - cnt1 % 2;
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) {
      cout << 1 << " \n"[i == cnt - 1];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
