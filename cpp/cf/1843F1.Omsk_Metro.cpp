#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

struct Info {
  int mi_suf = 0;
  int mx_suf = 0;
  int mi_ans = 0;
  int mx_ans = 0;
};

void solve() {
  int n;
  cin >> n;
  Info start = Info{};
  start.mx_suf = start.mx_ans = 1;
  vector<Info> st;
  st.push_back(start);
  for (int i = 0; i < n; i++) {
    char op;
    cin >> op;
    if (op == '+') {
      int v, x;
      cin >> v >> x;
      v--;
      auto pref = st[v];
      auto cur = Info{};
      cur.mi_suf = min(0, pref.mi_suf + x);
      cur.mx_suf = max(0, pref.mx_suf + x);
      cur.mi_ans = min(pref.mi_ans, cur.mi_suf);
      cur.mx_ans = max(pref.mx_ans, cur.mx_suf);
      st.push_back(cur);
    } else {
      int t, v, x;
      cin >> t >> v >> x;
      v--;
      if (st[v].mi_ans <= x && x <= st[v].mx_ans) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
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
