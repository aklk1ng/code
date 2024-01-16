#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

string cal(int n) {
  string res;
  while (n) {
    res += to_string(n % 2);
    n /= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}

void solve() {
  int n;
  cin >> n;
  string s = cal(n);
  int ans = 0;
  for (int i = (int)s.size() - 1; i >= 0; i--) {
    if (s[i] == '1') {
      break;
    }
    ans++;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
