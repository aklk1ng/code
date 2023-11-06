#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> a(n);
  vector<int> mi(n + 1, 9);
  for (int i = 0; i < n; i++) {
    a[i] = int(s[i] - '0');
  }
  for (int i = n - 1; i >= 0; i--) {
    mi[i] = min(mi[i + 1], a[i]);
  }

  vector<int> suff(10);
  string ans = "";
  string t = "0123456789";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < mi[i]; j++) {
      while (suff[j]) {
        suff[j]--;
        ans += t[j];
      }
    }
    if (a[i] == mi[i]) {
      ans += t[a[i]];
    } else {
      suff[min(9, a[i] + 1)]++;
    }
  }
  for (int j = 0; j < 10; j++) {
    while (suff[j]) {
      suff[j]--;
      ans += t[j];
    }
  }
  cout << ans << '\n';
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
