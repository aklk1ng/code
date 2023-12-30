#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ans;
bool ok = true;
void cal(int a, int b, string &t, vector<string> &str, vector<pair<int, int>> &match) {
  int mx = 0, id = -1, pos = -1;
  for (int i = a; i <= b; i++) {
    for (int j = 0; j < (int)str.size(); j++) {
      string s = str[j];
      if (i + s.size() > t.size() || i + (int)s.size() <= b) {
        continue;
      }
      if (t.substr(i, s.size()) == s) {
        if (i + s.size() > mx) {
          mx = i + s.size();
          id = j;
          pos = i;
        }
      }
    }
  }
  if (id == -1) {
    ok = false;
    return;
  } else {
    match.emplace_back(id, pos);
    ans++;
    if (mx == (int)t.size()) {
      return;
    } else {
      cal(max(pos + 1, b + 1), mx, t, str, match);
    }
  }
}
void solve() {
  ans = 0;
  ok = true;

  string t;
  cin >> t;
  int n;
  cin >> n;
  vector<string> s(n);
  vector<pair<int, int>> match;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  cal(0, 0, t, s, match);
  if (!ok) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
    for (auto &e : match) {
      cout << e.first + 1 << ' ' << e.second + 1 << '\n';
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
