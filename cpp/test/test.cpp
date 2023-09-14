// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e8;
#define ll long long
const int N = 1e6 + 5;

vector<int> v;
int n;
int good_ans, bad_ans;
vector<bool> vis(N);

void backtrace(int x, int sz, bool flag) {
  if (x > sz) {
    if (flag)
      good_ans++;
    else
      bad_ans++;
  }
  for (int i = x; i <= n; i++) {
    vis[x] = true;
    v.push_back(x);
    backtrace(x + 1, sz, flag);
    vis[x] = false;
    v.pop_back();
  }
}

void check(int sz, bool flag) {
  for (int i = 1; i <= n; i++) {
    backtrace(i, sz, flag);
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    vis.clear();
    if (i % 2) {
      check(i, true);
    } else {
      check(i, false);
    }
  }
  cout << good_ans - bad_ans << '\n';
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
