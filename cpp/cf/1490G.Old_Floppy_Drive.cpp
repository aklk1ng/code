#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  ll sum = 0;
  vector<ll> pref;
  vector<int> ind;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (pref.empty() || sum > pref.back()) {
      pref.push_back(sum);
      ind.push_back(cur);
    }
    cur++;
  }
  for (int i = 0; i < m; i++) {
    ll x;
    cin >> x;
    if (pref.back() < x && sum <= 0) {
      cout << -1 << ' ';
      continue;
    }
    ll need = 0;
    if (pref.back() < x) {
      need = (x - pref.back() + sum - 1) / sum;
    }
    x -= need * sum;
    cout << need * n + ind[lower_bound(pref.begin(), pref.end(), x) - pref.begin()] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (true) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
