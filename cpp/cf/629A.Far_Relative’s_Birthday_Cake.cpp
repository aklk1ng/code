#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[i] = s;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'C') {
        for (int k = i + 1; k < n; k++) {
          if (a[k][j] == 'C') {
            ans++;
          }
        }
        for (int k = j + 1; k < n; k++) {
          if (a[i][k] == 'C') {
            ans++;
          }
        }
      }
    }
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
