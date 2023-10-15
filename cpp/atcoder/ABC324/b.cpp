#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  ll n;
  cin >> n;
  auto check = [&]() {
    while (n % 2 == 0) {
      n /= 2;
    }
    while (n % 3 == 0) {
      n /= 3;
    }
    return n == 1;
  };
  cout << (check() ? "Yes\n" : "No\n");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
