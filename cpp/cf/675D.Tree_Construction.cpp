#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  set<int> nums;
  map<int, int> l;
  map<int, int> r;
  int n, x;
  cin >> n >> x;
  nums.insert(x);
  for (int i = 0; i < n - 1; i++) {
    cin >> x;
    auto it = nums.upper_bound(x);
    int ans;
    if (it != nums.end() && !l.count(*it)) {
      l[*it] = x;
      ans = *it;
    } else {
      it--;
      r[*it] = x;
      ans = *it;
    }
    nums.insert(x);
    cout << ans;
    if (i == n - 2) {
      cout << '\n';
    } else {
      cout << ' ';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  if (false) {
    cin >> tt;
  }
  while (tt--) {
    solve();
  }

  return 0;
}
