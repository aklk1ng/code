#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 1e5 + 5;

map<char, vector<pair<int, int>>> mp;

void solve() {
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      char c;
      cin >> c;
      mp[c].push_back({i, j});
    }
  }
  string s = "XO+.";
  for (int i = 1; i <= 3; i++) {
    int x1, y1, x2, y2, x3, y3;
    if (s[i] != '.') {
      x1 = mp[s[i]][0].first;
      y1 = mp[s[i]][0].second;
      x2 = mp[s[i]][1].first;
      y2 = mp[s[i]][1].second;
      x3 = mp[s[i]][2].first;
      y3 = mp[s[i]][2].second;
    }

    if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3) ||
        (abs(x1 - x2) == abs(y1 - y2) && abs(x2 - x3) == abs(y2 - y3))) {
      cout << s[i] << '\n';
      return;
    }
  }
  cout << "DRAW\n";
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
