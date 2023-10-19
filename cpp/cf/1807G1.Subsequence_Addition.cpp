#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (a[0] != 1) {
    cout << "No\n";
    return;
  }
  vector<int> dp(5e3 + 5);
  dp[1] = 1;
  for (int i = 1; i < n; i++) {
    if (!dp[a[i]]) {
      cout << "No\n";
      return;
    }
    for (int j = 5000; j >= a[i]; j--) {
      dp[j] |= dp[j - a[i]];
    }
  }
  cout << "Yes\n";
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
