#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<char> v;
  int i = 0;
  while (i < n) {
    if (v.count(s[i])) {
      cout << "No\n";
      return;
    } else {
      v.insert(s[i]); 
      int j = i + 1;
      while (s[j] == s[i]) {
        j++;
      }
      i = j;
    }
  }
  cout << "Yes\n";
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
