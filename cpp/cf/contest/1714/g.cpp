#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

vector ch(N, vector<int>());
vector<int> a(N), b(N), ans(N);
vector<ll> vb;
ll curb = 0, cura = 0;

void dfs(int x) {
  curb += b[x];
  cura += a[x];
  vb.push_back(curb);
  ans[x] = upper_bound(vb.begin(), vb.end(), cura) - vb.begin();
  for (int &e : ch[x]) {
    dfs(e);
  }
  curb -= b[x];
  cura -= a[x];
  vb.pop_back();
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ch[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int pr, a1, b1;
    cin >> pr >> a1 >> b1;
    pr--;
    ch[pr].push_back(i);
    a[i] = a1;
    b[i] = b1;
  }
  dfs(0);
  for (int i = 1; i < n; i++) {
    cout << ans[i] - 1 << " \n"[i == n - 1];
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
