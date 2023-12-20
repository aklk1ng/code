#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, q;
  cin >> n >> q;
  deque<int> d;
  int mx = -1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    d.push_back(x);
    mx = max(mx, x);
  }

  map<int, pair<int, int>> ans;
  int idx = 0;
  while (true) {
    int fst = d.front();
    d.pop_front();
    int sec = d.front();
    d.pop_front();

    if (fst == mx) {
      d.push_front(sec);
      d.push_front(fst);
      break;
    }
    idx++;
    ans[idx] = {fst, sec};
    if (sec > fst) {
      swap(fst, sec);
    }
    d.push_front(fst);
    d.push_back(sec);
  }

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = d.front();
    d.pop_front();
  }

  for (int i = 0; i < q; i++) {
    ll x;
    cin >> x;
    if (x <= idx) {
      cout << ans[x].first << ' ' << ans[x].second << '\n';
    } else {
      cout << mx << ' ' << a[(x - (idx + 1)) % (n - 1) + 1] << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
