#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<set<int>> map(26);
  for (int i = 0; i < n; i++) {
    map[s[i] - 'a'].insert(i);
  }

  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      pos--;
      map[s[pos] - 'a'].erase(pos);
      s[pos] = c;
      map[s[pos] - 'a'].insert(pos);
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int ans = 0;
      for (int i = 0; i < 26; i++) {
        auto it = map[i].lower_bound(l);
        if (it != map[i].end() && *it <= r) {
          ans++;
        }
      }
      cout << ans << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
