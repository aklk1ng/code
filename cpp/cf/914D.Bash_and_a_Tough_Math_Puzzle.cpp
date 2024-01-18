#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 2e6;

vector<int> tree(N);
int t = 1;

void query(int root, int u, int v, int x, int s, int e, int &ans) {
  if (e < s || v < u || e < u || v < s) {
    return;
  } else if (u <= s && e <= v) {
    if (tree[root] % x == 0) {
      return;
    } else {
      while (root < t) {
        if (tree[2 * root] % x) {
          if (tree[2 * root + 1] % x) {
            ans += 2;
            return;
          }
          root *= 2;
        } else {
          root = 2 * root + 1;
        }
      }
      ans++;
      return;
    }
  }
  int m = (s + e) / 2;
  query(2 * root, u, v, x, s, m, ans);
  if (ans > 1) {
    return;
  }
  query(2 * root + 1, u, v, x, m + 1, e, ans);
}

void update(int p, int x) {
  p += t - 1;
  tree[p] = x;
  p /= 2;
  while (p > 0) {
    tree[p] = __gcd(tree[2 * p], tree[2 * p + 1]);
    p /= 2;
  }
}

void solve() {
  int n;
  cin >> n;
  while (t < n) {
    t *= 2;
  }
  for (int i = t; i < t + n; i++) {
    cin >> tree[i];
  }
  for (int i = t - 1; i >= 1; i--) {
    tree[i] = __gcd(tree[2 * i], tree[2 * i + 1]);
  }
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      int ans = 0;
      query(1, l, r, x, 1, t, ans);
      cout << (ans <= 1 ? "YES" : "NO") << '\n';
    } else {
      int i, y;
      cin >> i >> y;
      update(i, y);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (false) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
