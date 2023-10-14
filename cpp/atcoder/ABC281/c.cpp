#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  vector<ll> suff(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    suff[i] = suff[i - 1] + a[i];
  }
  ll rest = k % suff[n];
  for (int i = 1; i <= n; i++) {
    if (suff[i] >= rest) {
      cout << i << ' ' << rest - suff[i - 1] << '\n';
      return;
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
