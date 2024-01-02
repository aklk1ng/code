#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  queue<int> q;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && s[i] != s[i - 1]) {
      cur++;
    }
    if (i > 0 && s[i] == s[i - 1]) {
      q.push(cur);
    }
  }
  int deleted = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    if (q.empty()) {
      break;
    }
    q.pop();
    deleted++;
    ans++;
    while (!q.empty() && q.front() == i) {
      q.pop();
      deleted++;
    }
    deleted++;
  }
  ans += (n - deleted + 1) / 2;
  cout << ans << '\n';
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
