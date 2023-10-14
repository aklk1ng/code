#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  priority_queue<ll> pq;
  int x;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 0) {
      if (!pq.empty()) {
        ans += pq.top();
        pq.pop();
      } 
    } else {
      pq.push(x);
    }
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
