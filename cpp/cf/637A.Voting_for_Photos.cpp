#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  map<int, int> m;
  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x]++;
    if (m[x] > cnt) {
      ans = x;
      cnt = m[x];
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
