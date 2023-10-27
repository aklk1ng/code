#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<char>> v(n);
  vector<bool> vis(256);

  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      cur++;
    } else if (s[i] == ')') {
      for (char &c : v[cur]) {
        vis[c] = false;
      }
      v[cur].clear();
      cur--;
    } else {
      if (vis[s[i]]) {
        cout << "No\n";
        return;
      }
      v[cur].push_back(s[i]);
      vis[s[i]] = true;
    }
  }
  cout << "Yes\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
