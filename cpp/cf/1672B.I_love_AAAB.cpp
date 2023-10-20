#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  bool ok = s.back() == 'B';
  int cnt = 0;
  for (auto &c : s) {
    if (c == 'A') {
      cnt++;
    } else {
      cnt--;
    }
    if (cnt < 0) {
      ok = false;
    }
  }
  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
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
