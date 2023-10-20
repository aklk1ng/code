#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  set<string> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.insert(s);
  }
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (v.count(s)) {
      cnt++;
    }
  }
  n -= cnt;
  m -= cnt;
  if (cnt & 1) {
    if (n >= m) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  } else {
    if (n <= m) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
