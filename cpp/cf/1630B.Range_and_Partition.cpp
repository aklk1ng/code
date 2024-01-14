#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector b = a;
  sort(b.begin(), b.end());

  int sum = (n + k + 1) / 2;
  pair<int, pair<int, int>> ans = {n + 1, {-1, -1}};
  for (int i = 0; i + sum - 1 < n; i++) {
    ans = min(ans, {b[i + sum - 1] - b[i], {b[i], b[i + sum - 1]}});
  }
  cout << ans.second.first << ' ' << ans.second.second << '\n';

  int pos = 0, cur = 0, lst = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] >= ans.second.first && a[i] <= ans.second.second) {
      cur++;
    } else {
      cur--;
    }
    if (cur > 0 && pos + 1 < k) {
      cout << lst << ' ' << i + 1 << '\n';
      lst = i + 2;
      pos++;
      cur = 0;
    }
  }
  pos++;
  cout << lst << ' ' << n << '\n';
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
