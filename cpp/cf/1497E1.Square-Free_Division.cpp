#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e7 + 5;

vector<int> primes, mind(N);
void init() {
  for (int i = 2; i <= N; i++) {
    if (mind[i] == 0) {
      primes.emplace_back(i);
      mind[i] = i;
    }
    for (auto &e : primes) {
      if (e > mind[i] || e * i > N) {
        break;
      }
      mind[e * i] = e;
    }
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int cnt = 0, last = 0;
    while (x > 1) {
      int p = mind[x];
      if (last == p) {
        cnt++;
      } else {
        if (cnt % 2) {
          a[i] *= last;
        }
        last = p;
        cnt = 1;
      }
      x /= p;
    }
    if (cnt % 2) {
      a[i] *= last;
    }
  }

  int l = 0, ans = 1;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    if (m.find(a[i]) != m.end() && m[a[i]] >= l) {
      ans++;
      l = i;
    }
    m[a[i]] = i;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
