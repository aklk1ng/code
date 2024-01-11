#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;

inline int add(int a, int b) { return (a + b >= mod ? a + b - mod : a + b); }

inline int mul(int a, int b) { return 1LL * a * b % mod; }

void solve() {
  int n, m, k;
  cin >> n >> m;
  vector<int> a(n), cnt(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto build = [&]() {
    sort(a.begin(), a.end());
    vector<int> b(a);
    k = unique(a.begin(), a.end()) - a.begin();
    for (int j = 0; j < k; j++) {
      cnt[j] = upper_bound(b.begin(), b.end(), a[j]) - lower_bound(b.begin(), b.end(), a[j]);
    }
  };
  auto push = [&](stack<pair<int, int>> &s, int x) {
    s.emplace(x, mul(x, s.empty() ? 1 : s.top().second));
  };
  auto cal = [&]() {
    if (k < m) {
      return 0;
    }
    stack<pair<int, int>> s1, s2;
    for (int j = 0; j < m; j++) {
      push(s1, cnt[j]);
    }
    int ans = 0;
    for (int j = m; j <= k; j++) {
      if (a[j - 1] - a[j - m] == m - 1) {
        ans = add(ans, mul(s1.empty() ? 1 : s1.top().second, s2.empty() ? 1 : s2.top().second));
      }
      if (s2.empty()) {
        while (!s1.empty()) {
          push(s2, s1.top().first);
          s1.pop();
        }
      }
      s2.pop();
      push(s1, cnt[j]);
    }
    return ans;
  };
  build();
  cout << cal() << '\n';
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
