#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  string digits;
  cin >> digits;
  map<char, int> m;
  for (int i = 0; i < (int)digits.size(); i++) {
    m[digits[i]] = i + 1;
  }
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < (int)s.size() - 1; i++) {
    ans += abs(m[s[i + 1]] - m[s[i]]);
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
