#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  if (n != 8) {
    cout << "No\n";
  } else {
    char l = s[0];
    string nums = s.substr(1, n - 2);
    char r = s[n - 1];
    if (isupper(l) && isupper(r) && nums <= "999999" && nums >= "100000") {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
