#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  map<int, int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (!a[x]) {
      cout << "No\n";
      return;
    }
    a[x]--;
  }

  cout << "Yes\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
