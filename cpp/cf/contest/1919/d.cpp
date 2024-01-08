#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  priority_queue<pair<int, int>> pq;
  vector<int> a(N), pre(N), nxt(N);
  vector<bool> in(N);
  auto good = [&](int i) {
    if (i < 1 || i > n) {
      return false;
    }
    return a[pre[i]] == a[i] - 1 || a[nxt[i]] == a[i] - 1;
  };
  for (int i = 1; i <= n; i++) {
    pre[i] = i - 1;
    nxt[i] = i + 1;
    in[i] = false;
    cin >> a[i];
  }
  a[n + 1] = a[0] = -2;
  for (int i = 1; i <= n; i++) {
    if (good(i)) {
      in[i] = true;
      pq.push({a[i], i});
    }
  }

  while (!pq.empty()) {
    auto [_, i] = pq.top();
    pq.pop();
    nxt[pre[i]] = nxt[i];
    pre[nxt[i]] = pre[i];
    if (!in[pre[i]] && good(pre[i])) {
      in[pre[i]] = true;
      pq.push({a[pre[i]], pre[i]});
    }
    if (!in[nxt[i]] && good(nxt[i])) {
      in[nxt[i]] = true;
      pq.push({a[nxt[i]], nxt[i]});
    }
  }

  int mi = n, bad = 0;
  for (int i = 1; i <= n; i++) {
    bad += !in[i];
    mi = min(mi, a[i]);
  }

  if (bad == 1 && mi == 0) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
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
