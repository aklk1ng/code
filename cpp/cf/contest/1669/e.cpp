#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> cnt(12, vector<int>(12));
  ll ans = 0;
  string x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 0; j < 2; j++) {
      for (char c = 'a'; c <= 'k'; c++) {
        if (c == x[j]) {
          continue;
        }
        string a = x;
        a[j] = c;
        ans += cnt[a[0] - 'a'][a[1] - 'a'];
      }
    }
    cnt[x[0] - 'a'][x[1] - 'a']++;
  }
  cout << ans << '\n';
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
