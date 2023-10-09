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
  int ans = 0;
  map<char, int> m;
  for (auto &c : s) {
    m[c]++;
  }
  for (auto &[k, v] : m) {
    if (v >= 2) {
      ans += v + 1;
    } else {
      ans += 2;
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