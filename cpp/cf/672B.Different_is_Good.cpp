#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, int> m;
  for (auto &c : s) {
    m[c]++;
  }

  int diff = 0;
  for (auto &[k, v] : m) {
    if (v > 1) {
      diff += v - 1;
    }
  }

  if (diff + (int)m.size() > 26) {
    cout << -1 << '\n';
  } else {
    cout << diff << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
