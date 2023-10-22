#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(26);
  for (int i = 0; i < n; i++) {
    int w, x;
    cin >> w >> x;
    cnt[x] += w;
  }
  int ans = -1;
  for (int i = 0; i < 26; i++) {
    int tot = 0;
    for (int j = 0; j < 9; j++) {
      tot += cnt[(i + j) % 24];
    }
    ans = max(ans, tot);
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
