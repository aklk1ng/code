#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

vector<int> v[1001];
void solve() {
  int n;
  cin >> n;
  vector<int> id[1001];
  int x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    id[x].push_back(i);
  }
  int ans = -1;
  for (int i = 1; i <= 1000; i++) {
    for (int j : v[i]) {
      if (!id[i].empty() && !id[j].empty()) {
        ans = max(ans, id[i].back() + id[j].back());
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      if (__gcd(i, j) == 1) {
        v[i].push_back(j);
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
