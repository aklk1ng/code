#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  string s;
  cin >> s;
  map<char, int> m;
  for (auto &c : s) {
    m[c]++;
  }
  for (auto &[k, v] : m) {
    if (v >= 2) {
      cout << k << k;
    } else {
      cout << k;
    }
  }
  cout << '\n';
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
