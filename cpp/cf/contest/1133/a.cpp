#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int h1, m1, h2, m2;
  char op;
  cin >> h1 >> op >> m1;
  cin >> h2 >> op >> m2;
  int t1 = h1 * 60 + m1;
  int t2 = h2 * 60 + m2;
  int mid = (t1 + t2) / 2;
  cout << setw(2) << setfill('0') << mid / 60 << ':' << setw(2) << setfill('0') << mid % 60 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
