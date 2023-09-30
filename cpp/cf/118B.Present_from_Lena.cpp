#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    for (int j = i; j < n; j++) {
      cout << ' ' << ' ';
    }
    for (int j = 0; j <= i; j++) {
      if (i == 0) {
        cout << j;
      } else {
        cout << j << ' ';
      }
    }
    for (int j = i - 1; j >= 0; j--) {
      if (j > 0) {
        cout << j << ' ';
      } else {
        cout << j;
      }
    }
    cout << '\n';
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << ' ' << ' ';
    }
    for (int j = 0; j <= n - 1 - i; j++) {
      if (i == n - 1) {
        cout << j;
      } else {
        cout << j << ' ';
      }
    }
    for (int j = n - i - 2; j >= 0; j--) {
      if (j > 0) {
        cout << j << ' ';
      } else {
        cout << j;
      }
    }
    if (i < n - 1) {
      cout << '\n';
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
