#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<char, int> m;
  for (auto &c : s) {
    m[c]++;
  }
  int cnt = 0;
  for (auto &[a, v] : m) {
    if (v % 2) {
      cnt++;
    }
  }
  cout << (cnt > k + 1 ? "no" : "yes") << '\n';
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
