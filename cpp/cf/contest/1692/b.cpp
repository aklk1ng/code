#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  int x;
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s.insert(x);
  }
  if ((n - s.size()) % 2 == 0) {
    cout << s.size() << '\n';
  } else {
    cout << s.size() - 1 << '\n';
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
