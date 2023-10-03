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
  if (n != 5) {
    cout << "No\n";
    return;
  }
  set<char> ans;
  ans.insert('T');
  ans.insert('i');
  ans.insert('m');
  ans.insert('u');
  ans.insert('r');
  for (int i = 0; i < n; i++) {
    if (ans.count(s[i])) {
      ans.erase(s[i]);
    }
  }
  cout << (ans.size() == 0 ? "Yes\n" : "No\n");
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
