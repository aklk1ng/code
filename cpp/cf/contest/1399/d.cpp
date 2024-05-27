#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ans(n), pos0, pos1;
  for (int i = 0; i < n; i++) {
    int newpos = pos0.size() + pos1.size();
    if (s[i] == '0') {
      if (pos1.empty()) {
        pos0.push_back(newpos);
      } else {
        newpos = pos1.back();
        pos1.pop_back();
        pos0.push_back(newpos);
      }
    } else {
      if (pos0.empty()) {
        pos1.push_back(newpos);
      } else {
        newpos = pos0.back();
        pos0.pop_back();
        pos1.push_back(newpos);
      }
    }
    ans[i] = newpos;
  }
  cout << pos0.size() + pos1.size() << '\n';
  for (auto &e : ans) {
    cout << e + 1 << " ";
  }
  cout << '\n';
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
