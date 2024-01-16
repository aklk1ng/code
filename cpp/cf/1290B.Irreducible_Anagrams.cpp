#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  s = '0' + s;
  vector sum(n + 1, vector<int>(26));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      sum[i][j] += sum[i - 1][j];
    }
    sum[i][s[i] - 'a']++;
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
      cnt += (sum[r][i] - sum[l - 1][i] > 0);
    }
    if (l == r || cnt >= 3 || s[l] != s[r]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
