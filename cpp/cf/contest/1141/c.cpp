#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;

  vector<int> q(n - 1);
  ll sum = 0;
  ll mi = 0;
  for (int i = 0; i < n - 1; i++) {
    cin >> q[i];
    sum += q[i];
    if (sum < mi) {
      mi = sum;
    }
  }
  vector<ll> p(n);
  p[0] = 1 - mi;
  for (int i = 0; i < n - 1; i++) {
    p[i + 1] = p[i] + q[i];
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (p[i] < 1 || p[i] > n) {
      ok = false;
    }
  }
  if (ok) {
    ok = (int)set<ll>(p.begin(), p.end()).size() == n;
  }
  if (ok) {
    for (int i = 0; i < n; i++) {
      cout << p[i] << " \n"[i == n - 1];
    }
  } else {
    cout << -1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
