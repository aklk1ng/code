#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(2 * n + 1);
  vector<int> odd, even;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
    if (a[i] % 2) {
      odd.push_back(i);
    } else {
      even.push_back(i);
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < (int)odd.size() - 1; i += 2) {
    ans.push_back({odd[i], odd[i + 1]});
  }
  for (int i = 0; i < (int)even.size() - 1; i += 2) {
    ans.push_back({even[i], even[i + 1]});
  }

  for (int i = 0; i < n - 1; i++) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
