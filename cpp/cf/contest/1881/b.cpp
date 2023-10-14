#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> v;
  int mi = min({a, b, c});
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  int cnt = 0;
  for (int &e : v) {
    while (e != mi) {
      e -= mi;
      cnt++;
      if (cnt > 3) {
        cout << "No\n";
        return;
      }
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
