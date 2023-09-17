#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sx = 0, sy = 0;
  for (auto &c : s) {
    if (c == 'U') {
      sy++;
    } else if (c == 'D') {
      sy--;
    } else if (c == 'L') {
      sx--;
    } else if (c == 'R') {
      sx++;
    }
    if (sx == 1 && sy == 1) {
      cout << "Yes\n";
      return;
    }
  }
  if (sx == 1 && sy == 1) {
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
