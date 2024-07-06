#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  priority_queue<int> qa(a.begin(), a.end());
  priority_queue<int> qb(b.begin(), b.end());

  int ans = 0;
  while (!qa.empty()) {
    if (qa.top() == qb.top()) {
      qa.pop();
      qb.pop();
      continue;
    }
    ans++;
    if (qa.top() > qb.top()) {
      qa.push(to_string(qa.top()).size());
      qa.pop();
    } else {
      qb.push(to_string(qb.top()).size());
      qb.pop();
    }
  }
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
