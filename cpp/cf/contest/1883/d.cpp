#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  multiset<int> left, right;
  int q;
  cin >> q;
  while (q--) {
    char op;
    int l, r;
    cin >> op >> l >> r;
    if (op == '+') {
      left.insert(l);
      right.insert(r);
    } else {
      left.erase(left.find(l));
      right.erase(right.find(r));
    }

    if (left.size() <= 1) {
      cout << "no\n";
      continue;
    }
    if (left.upper_bound(*right.begin()) == left.end()) {
      cout << "no\n";
      continue;
    }
    cout << "yes\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
