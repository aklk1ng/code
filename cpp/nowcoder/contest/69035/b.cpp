#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  while (k > 0) {
    int l = -1, r = -1, len = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        int j = i + 1;
        while (j < n && s[j] == s[i]) {
          j++;
        }
      }

    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
