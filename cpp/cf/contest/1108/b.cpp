#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  multiset<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  int x = *prev(s.end());
  for (int i = 1; i <= x; i++) {
    if (x % i == 0) {
      s.erase(s.find(i));
    }
  }

  cout << x << ' ' << *prev(s.end()) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
