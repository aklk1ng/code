#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  ll a = 0, b = 0, c = 0;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a += x;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> x;
    b += x;
  }
  for (int i = 0; i < n - 2; i++) {
    cin >> x;
    c += x;
  }
  cout << a - b << '\n' << b - c << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
