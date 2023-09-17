#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 2e5 + 5;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(26), p(26);
  for (auto &c : s) {
    cnt[c - 'a']++;
  }
  int ans = 0;
  for (auto &c : s) {
    cnt[c - 'a']--;
    p[c - 'a']++;
    int cur = 0;
    for (int i = 0; i < 26; i++) {
      cur += min(1, cnt[i]) + min(1, p[i]);
    }
    ans = max(ans, cur);
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
