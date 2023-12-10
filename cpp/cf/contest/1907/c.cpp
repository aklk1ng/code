#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (auto &e : s) {
    cnt[e - 'a'] += 1;
  }
  int mx = *max_element(cnt.begin(), cnt.end());
  cout << max(n % 2, 2 * mx - n) << '\n';
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
