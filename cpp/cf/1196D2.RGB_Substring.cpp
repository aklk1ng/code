#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int q;
  cin >> q;
  const string t = "RGB";
  for (int i = 0; i < q; i++) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 1e9;
    for (int offset = 0; offset < 3; offset++) {
      vector<int> res(n);
      int cur = 0;
      for (int j = 0; j < n; j++) {
        res[j] = (s[j] != t[(j + offset) % 3]);
        cur += res[j];
        if (j >= k) {
          cur -= res[j - k];
        }
        if (j >= k - 1) {
          ans = min(ans, cur);
        }
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
