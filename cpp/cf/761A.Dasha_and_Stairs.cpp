#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int a, b;
  cin >> a >> b;
  if (abs(a - b) > 1 || (a == 0 && b == 0)) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
