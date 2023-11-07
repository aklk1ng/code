#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<string> v(n);
  set<string> s;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (!s.count(v[i])) {
      s.insert(v[i]);
      cout << v[i] << '\n';
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
