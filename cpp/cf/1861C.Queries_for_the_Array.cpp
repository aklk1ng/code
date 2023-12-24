#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ans;
vector<int> has0, has1;
vector<vector<int>> g;
bool dfs(int x, int d) {
  if (has0[x] && (has1[x] || d <= 1)) {
    ans = false;
  }
  bool res = false;
  for (auto &y : g[x]) {
    res |= dfs(y, d + 1);
  }
  if (has0[x] && res) {
    ans = false;
  }
  return res || has1[x];
}

void solve() {
  ans = true;
  has0.push_back(0);
  has1.push_back(0);
  g.push_back(vector<int>());
  int ts = 1;

  string s;
  cin >> s;
  vector<int> st = {0};
  for (auto &e : s) {
    int cur = st.back();
    if (e == '0') {
      has0[cur] = 1;
    }
    if (e == '1') {
      has1[cur] = 1;
    }
    if (e == '+') {
      g[cur].push_back(ts);
      st.push_back(ts);
      ts++;
      has0.push_back(0);
      has1.push_back(0);
      g.push_back(vector<int>());
    }
    if (e == '-') {
      st.pop_back();
    }
  }
  dfs(0, 0);
  cout << (ans ? "Yes" : "No") << '\n';
  has0.clear();
  has1.clear();
  g.clear();
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
