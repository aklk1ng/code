#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(k);
  for (int i = 0; i < k; i++) {
    cin >> b[i];
  }

  sort(b.rbegin(), b.rend());
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      a[i] = *b.begin();
      b.erase(b.begin());
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] >= a[i + 1]) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
