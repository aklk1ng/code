#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll s = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    s += x;
    pq.push(x);
    while (s < 0) {
      s -= pq.top();
      pq.pop();
    }
  }
  cout << pq.size() << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
