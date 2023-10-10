#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  string s;
  cin >> s;
  vector<string> digits;
  digits.push_back("00");
  digits.push_back("25");
  digits.push_back("50");
  digits.push_back("75");
  auto check = [&](string str, string t) -> int {
    int n = str.size() - 1;
    int ans = 0;
    while (n >= 0 && str[n] != t[1]) {
      n--;
      ans++;
    }
    if (n < 0) {
      return INF;
    }
    n--;
    while (n >= 0 && str[n] != t[0]) {
      n--;
      ans++;
    }
    return n < 0 ? INF : ans;
  };
  int ans = INF;
  for (auto &digit : digits) {
    ans = min(ans, check(s, digit));
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
