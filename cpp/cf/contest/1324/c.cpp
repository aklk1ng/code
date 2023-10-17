#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  vector<int> pos;
  pos.push_back(0);
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      pos.push_back(i + 1);
    }
  }
  pos.push_back(n + 1);
  int ans = 0;
  for (int i = 0; i < (int)pos.size() - 1; i++) {
    ans = max(ans, pos[i + 1] - pos[i]);
  }
  cout << ans << '\n';
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
