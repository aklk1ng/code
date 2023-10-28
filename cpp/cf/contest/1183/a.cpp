#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  auto cal = [&](int x) {
    int res = 0;
    while (x) {
      res += x % 10;
      x /= 10;
    }
    return res;
  };
  int sum = cal(n);
  if (sum % 4 == 0) {
    cout << n << '\n';
  } else {
    while (sum % 4) {
      n++;
      sum = cal(n);
    }
    cout << n << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
