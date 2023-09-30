#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  string s;
  cin >> s;
  int ans = 0;
  set<char> v;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    v.insert(s[i]);
    if (v.size() > 3) {
      v.clear();
      ans++;
      v.insert(s[i]);
    }
  }
  if (!v.empty()) {
    ans++;
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
