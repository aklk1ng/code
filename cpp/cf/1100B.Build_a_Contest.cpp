#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> freq(n);
  int dist = 0;
  auto cal = [&]() {
    for (int i = 0; i < n; i++) {
      if (--freq[i] == 0) {
        dist--;
      }
    }
  };
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    a--;
    if (freq[a]++ == 0) {
      dist++;
    }
    if (dist == n) {
      cal();
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
