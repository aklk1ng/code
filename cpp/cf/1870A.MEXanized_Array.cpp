#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  if (min(n, x + 1) < k) {
    cout << -1 << '\n';
    return;
  }

  vector<int> ans;
  for (int i = 0; i < k; i++) {
    ans.push_back(i);
  }
  if (k == x && n > k) {
    for (int i = k; i < n; i++) {
      ans.push_back(k - 1);
    }

  } else if (k != x && n > k) {
    for (int i = k; i < n; i++) {
      ans.push_back(x);
    }
  }
  cout << accumulate(ans.begin(), ans.end(), 0) << '\n';
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
