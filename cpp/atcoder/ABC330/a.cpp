#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, l;
  cin >> n >> l;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x >= l) {
      ans++;
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
