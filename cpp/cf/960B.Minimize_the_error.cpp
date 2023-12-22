#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k1, k2, k;
  cin >> n >> k1 >> k2;
  k = k1 + k2;

  priority_queue<ll> pq;
  vector<int> a(n), b(n), arr(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    arr[i] = abs(a[i] - b[i]);
    pq.push(arr[i]);
  }

  while (k > 0) {
    ll cur = pq.top();
    pq.pop();
    pq.push(abs(cur - 1));
    k--;
  }

  ll ans = 0;
  while (!pq.empty()) {
    ll cur = pq.top();
    pq.pop();
    ans += cur * cur;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
