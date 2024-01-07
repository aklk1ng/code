#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  multiset<int> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.insert(x);
  }
  for (int i = 0; i < n; i++) {
    auto it = b.lower_bound(n - a[i]);
    if (it == b.end()) {
      it = b.begin();
    }
    cout << (a[i] + *it) % n << " \n"[i == n - 1];
    b.erase(it);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
