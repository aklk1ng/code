#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  vector<int> a(10);
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int pre = 0;
  for (int i = 0; i < 3; i++) {
    ans = a[pre];
    pre = ans;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
