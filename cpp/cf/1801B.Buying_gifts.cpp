#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 0x3f3f3f3f;

template <typename T>
bool smin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool smax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end(), [&](const auto &p1, const auto &p2) {
    return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
  });

  multiset<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(a[i].first);
  }

  int mx = -INF, ans = INF;
  for (int i = 1; i < n; i++) {
    smin(ans, abs(a[i].first - a[0].second));
  }
  for (int i = 0; i < n; i++) {
    s.erase(s.find(a[i].first));
    if (i == 0) {
      mx = a[i].first;
      continue;
    }
    smin(ans, abs(mx - a[i].second));
    auto it = s.lower_bound(a[i].second);
    if (it != s.end() && *it >= mx) {
      smin(ans, abs(*it - a[i].second));
    }
    if (it != s.begin() && *prev(it) >= mx) {
      smin(ans, abs(*prev(it) - a[i].second));
    }
    smax(mx, a[i].first);
  }
  cout << ans << '\n';
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
