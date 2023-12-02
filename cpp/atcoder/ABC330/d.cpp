#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> bi(n), bj(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'o') {
        bi[i]++;
        bj[j]++;
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'o') {
        ans += (bi[i] - 1) * (bj[j] - 1);
      }
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
