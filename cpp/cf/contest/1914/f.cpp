#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;

vector<int> g[N];
int sz[N];

void init(int v) {
  sz[v] = 1;
  for (auto &e : g[v]) {
    init(e);
    sz[v] += sz[e];
  }
}

int cal(int v, int k) {
  int sum = 0, mx = -1;
  for (auto &e : g[v]) {
    sum += sz[e];
    if (mx == -1 || sz[mx] < sz[e]) {
      mx = e;
    }
  }
  if (sum == 0) {
    return 0;
  }
  if (sz[mx] - k <= sum - sz[mx]) {
    return (sum - k) / 2;
  }
  int add = sum - sz[mx];
  return add + cal(mx, max(0, k + add - 1));
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    g[x - 1].push_back(i);
  }
  init(0);
  cout << cal(0, 0) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
