#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  multiset<int> a, b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (x % 2 == 0) {
      x /= 2;
    }
    a.insert(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.insert(x);
  }

  n = a.size();
  while (!b.empty()) {
    auto x = *b.rbegin();
    if (!a.count(x)) {
      if (x == 1) {
        break;
      }
      b.erase(b.find(x));
      b.insert(x / 2);
    } else {
      b.erase(b.find(x));
      a.erase(a.find(x));
    }
  }

  cout << (b.empty() ? "Yes" : "No") << '\n';
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
