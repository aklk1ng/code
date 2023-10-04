#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  map<string, bool> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    m[s[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    bool ok = false;
    for (int j = 1; j < s[i].length(); j++) {
      string pre = s[i].substr(0, j), suff = s[i].substr(j);
      if (m[pre] && m[suff]) {
        ok = true;
      }
    }
    cout << ok;
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
