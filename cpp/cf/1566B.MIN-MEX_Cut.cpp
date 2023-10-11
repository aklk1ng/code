#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  string s;
  cin >> s;
  int cnt = count(s.begin(), s.end(), '0');
  if (cnt == 0) {
    cout << 0 << '\n';
  } else {
    int l = s.find('0');
    int r = s.rfind('0');
    if (r - l + 1 == cnt) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
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
