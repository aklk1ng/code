#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  map<int, pair<int, int>> mp;
  for (int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    if (!mp.count(u)) {
      mp[u].first = i;
      mp[u].second = i;
    } else {
      mp[u].second = i;
    }
  }
  while (k--) {
    int a, b;
    cin >> a >> b;
    if (!mp.count(a) || !mp.count(b) || mp[a].first > mp[b].second) {
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
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
