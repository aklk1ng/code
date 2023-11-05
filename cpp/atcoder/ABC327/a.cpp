#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool ok = false;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b') {
      ok = true;
    }
    if (s[i] == 'b' && s[i + 1] == 'a') {
      ok = true;
    }
  }
  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
