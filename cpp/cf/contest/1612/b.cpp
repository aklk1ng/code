#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> p;
  p.push_back(a);
  for (int i = n; i > 0; i--) {
    if (i != a && i != b) {
      p.push_back(i);
    }
  }
  p.push_back(b);
  if ((int)p.size() == n && *min_element(p.begin(), p.begin() + n / 2) == a &&
      *max_element(p.begin() + n / 2, p.end()) == b) {
    for (auto &i : p) {
      cout << i << " \n"[i == p.back()];
    }
  } else {
    cout << -1 << '\n';
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
