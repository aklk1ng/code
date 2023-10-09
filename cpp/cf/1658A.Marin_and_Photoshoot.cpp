#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      v.push_back(i);
    }
  }
  int ans = 0;
  for (int i = 0; i < (int)v.size() - 1; i++) {
    if (v[i + 1] - v[i] <= 2) {
      ans += 2 - (v[i + 1] - v[i]) + 1;
    }
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
