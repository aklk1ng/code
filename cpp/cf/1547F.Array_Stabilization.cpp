#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

const int N = 1e6;
vector<int> sieve(N + 1), prime;

void init() {
  sieve[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (sieve[i] == 0) {
      sieve[i] = i;
      prime.push_back(i);
    }
    for (int j = 0; j < (int)prime.size() && prime[j] <= sieve[i] && i * prime[j] <= N; j++) {
      sieve[i * prime[j]] = prime[j];
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int common = a[0];
  vector<set<int>> facts(n);
  for (int i = 1; i < n; i++) {
    common = __gcd(common, a[i]);
  }
  for (int i = 0; i < n; i++) {
    int t = a[i] / common;
    while (t != 1) {
      facts[i].insert(sieve[t]);
      t /= sieve[t];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (auto &p : facts[i]) {
      int l = (i + n - 1) % n, r = i;
      int cnt = 0;
      while (facts[l].count(p) > 0) {
        facts[l].erase(p);
        l--, cnt++;
        if (l < 0) {
          l = n - 1;
        }
      }
      while (facts[r].count(p) > 0) {
        if (r != i) {
          facts[r].erase(p);
        }
        ++r %= n;
        cnt++;
      }
      ans = max(ans, cnt);
    }
    facts[i].clear();
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int T = 1;
  if (true) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
