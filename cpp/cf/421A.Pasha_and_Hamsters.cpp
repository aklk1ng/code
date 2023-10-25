#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  set<int> v1, v2;
  for (int i = 0; i < a; i++) {
    int x;
    cin >> x;
    v1.insert(x);
  }
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    v2.insert(x);
  }

  vector<int> v(n + 1, 1);
  if (a <= b) {
    for (int i = 1; i <= n; i++) {
      if (!v1.count(i)) {
        v[i] = 2;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (v2.count(i)) {
        v[i] = 2;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << v[i] << " \n"[i == n];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
