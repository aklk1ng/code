#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  deque<int> d;
  for (auto &i : p) {
    if (d.empty() || i < d.front()) {
      d.push_front(i);
    } else {
      d.push_back(i);
    }
  }
  for (auto &i : d) {
    cout << i << " \n"[i == d.back()];
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
