#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string t;
  cin >> t;
  int cnt0 = count(t.begin(), t.end(), '0');
  int cnt1 = count(t.begin(), t.end(), '1');
  if (!cnt0 || !cnt1) {
    cout << t << '\n';
  } else {
    int n = t.size();
    if (t[0] == '0') {
      for (int i = 0; i < n; i++) {
        cout << "01";
      }
      cout << '\n';
    } else {
      for (int i = 0; i < n; i++) {
        cout << "10";
      }
      cout << '\n';
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
