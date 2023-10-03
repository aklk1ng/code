#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> h;
  h.push_back(0);
  vector<int> premax;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    h.push_back(h.back() + x);
    if (i == 0) {
      premax.push_back(x);
    } else {
      premax.push_back(max(premax.back(), x));
    }
  }
  while (q--) {
    int k;
    cin >> k;
    int pos = upper_bound(premax.begin(), premax.end(), k) - premax.begin();
    cout << h[pos] << ' ';
  }
  cout << '\n';
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
