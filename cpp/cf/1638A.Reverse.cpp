#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  if (is_sorted(p.begin(), p.end())) {
    for (auto &i : p) {
      cout << i << " \n"[i == p.back()];
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (p[i] != i + 1) {
        for (int j = i + 1; j < n; j++) {
          if (p[j] == i + 1) {
            reverse(p.begin() + i, p.begin() + j + 1);
            break;
          }
        }
        for (auto &i : p) {
          cout << i << " \n"[i == p.back()];
        }
        return;
      }
    }
  }
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
