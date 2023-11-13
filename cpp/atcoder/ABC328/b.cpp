#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    string m = to_string(i);
    for (int d = 1; d <= a[i]; d++) {
      string date = m + to_string(d);
      if (int(size(set<char>(date.begin(), date.end())) == 1)) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
