#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans = "0000000000";
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      int pos = ans.find('0');
      ans[pos] = '1';
    } else if (s[i] == 'R') {
      int pos = ans.rfind('0');
      ans[pos] = '1';
    } else {
      ans[s[i] - '0'] = '0';
    }
  }
  for (auto &c : ans) {
    cout << c;
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
