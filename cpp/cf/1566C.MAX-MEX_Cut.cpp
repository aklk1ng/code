#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  auto cal = [&](string s) {
    int ans = count(s.begin(), s.end(), '0');
    int sz = s.size();
    bool ok1 = false, ok2 = false;
    for (int i = 0; i < sz; i++) {
      if (s[i] == '0') {
        ok1 = true;
      }
      if (s[i] == '1') {
        ok2 = true;
      }
      if (ok1 && ok2) {
        ans++;
        ok1 = ok2 = false;
      }
    }
    return ans;
  };

  string s = "";
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      ans += 2 + cal(s);
      s = "";
    } else {
      s += a[i];
    }
  }

  cout << ans + cal(s) << '\n';
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
