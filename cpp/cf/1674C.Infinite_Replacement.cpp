#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  auto check = [&]() -> int {
    int res = 0;
    for (auto &c : t) {
      if (c == 'a') {
        res++;
      }
    }
    return res;
  };
  if (t == "a") {
    cout << 1 << '\n';
  } else if (check() != 0) {
    cout << -1 << '\n';
  } else {
    cout << (ll)pow(2, s.size()) << '\n';
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
