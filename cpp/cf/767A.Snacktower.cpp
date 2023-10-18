#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> has(1e5 + 5);
  int cur = n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    has[x] = 1;
    while (has[cur]) {
      cout << cur << ' ';
      cur--;
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
