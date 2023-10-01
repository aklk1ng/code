#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  for (int i = 1; i <= 9; i++) {
    string s;
    cin >> s;
    for (auto &c : s) {
      if (c == '2') {
        c = '1';
      }
    }
    cout << s << '\n';
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
