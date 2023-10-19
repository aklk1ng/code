#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, t, c;
  cin >> n >> t >> c;
  vector<int> a;
  a.push_back(-1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > t) {
      a.push_back(i);
    }
  }
  a.push_back(n);
  ll ans = 0;
  for (int i = 1; i < (int)a.size(); i++) {
    int diff = a[i] - a[i - 1] - 1;
    ans += max(diff - c + 1, 0);
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
