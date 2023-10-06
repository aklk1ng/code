#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  ll k;
  cin >> k;
  vector<int> digits;
  while (k) {
    digits.push_back(k % 9);
    k /= 9;
  }
  reverse(digits.begin(), digits.end());
  for (int i = 0; i < (int)digits.size(); i++) {
    cout << (digits[i] < 4 ? digits[i] : digits[i] + 1);
  }
  cout << '\n';
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
