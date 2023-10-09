#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  string s;
  cin >> s;
  auto check = [&](string str) -> bool {
    for (int i = 0, j = str.size() - 1; i <= j; i++, j--) {
      if (str[i] != str[j]) {
        return true;
      }
    }
    return false;
  };
  if (check("a" + s)) {
    cout << "Yes\n";
    cout << "a" << s << '\n';
  } else if (check(s + "a")) {
    cout << "Yes\n";
    cout << s << "a" << '\n';
  } else {
    cout << "No\n";
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
