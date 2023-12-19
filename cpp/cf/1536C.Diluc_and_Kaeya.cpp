#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int d = 0, k = 0;
  map<pair<int, int>, int> m;
  auto get = [&](int a, int b) -> pair<int, int> {
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
  };
  for (auto &c : s) {
    if (c == 'D') {
      d++;
    } else {
      k++;
    }
    cout << ++m[get(d, k)] << ' ';
  }
  cout << '\n';
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
