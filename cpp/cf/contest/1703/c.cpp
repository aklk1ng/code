#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    string s;
    cin >> s;
    for (auto &c : s) {
      if (c == 'U') {
        if (a[i] > 0) {
          a[i]--;
        } else {
          a[i] = 9;
        }
      } else {
        if (a[i] < 9) {
          a[i]++;
        } else {
          a[i] = 0;
        }
      }
    }
    cout << a[i] << ' ';
  }
  cout << '\n';
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
