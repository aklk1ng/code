#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<bool> prime(100);

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
      cout << 1 << '\n';
      cout << s[i] << '\n';
      return;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!prime[(s[i] - '0') * 10 + s[j] - '0']) {
        cout << 2 << '\n';
        cout << s[i] << s[j] << '\n';
        return;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 2; i < 100; i++) {
    prime[i] = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        prime[i] = false;
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
