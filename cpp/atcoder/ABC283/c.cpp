#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  int ans = 0;
  while (!s.empty()) {
    auto c = s.back();
    s.pop_back();
    if (c == '0' && s.back() == '0') {
      s.pop_back();
    }
    ans++;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
