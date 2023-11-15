#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> p(3);
  iota(p.begin(), p.end(), 0);

  string color = "RGB";
  string res = "";
  int ans = 1e9;

  do {
    string t;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      t += color[p[i % 3]];
      cnt += t[i] != s[i];
    }
    if (ans > cnt) {
      ans = cnt;
      res = t;
    }
  } while (next_permutation(p.begin(), p.end()));

  cout << ans << '\n' << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
