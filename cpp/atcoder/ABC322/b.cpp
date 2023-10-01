#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, m;
  cin >> n >> m;
  string S;
  cin >> S;
  string T;
  cin >> T;
  int prefix = 0, suffix = 0;
  for (int i = 0; i < n; i++) {
    prefix += S[i] - T[i];
  }
  for (auto &c : S) {
    suffix += (int)c;
  }
  for (int i = m - 1; i >= m - n; i--) {
    suffix -= (int)T[i];
  }
  if (!prefix && !suffix) {
    cout << 0 << '\n';
  } else if (!prefix) {
    cout << 1 << '\n';
  } else if (!suffix) {
    cout << 2 << '\n';
  } else {
    cout << 3 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
