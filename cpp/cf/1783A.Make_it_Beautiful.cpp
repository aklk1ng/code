#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> prefix(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0) {
      prefix[i] = a[i];
    } else {
      prefix[i] = prefix[i - 1] + a[i];
    }
  }
  bool flag = false;
  for (int i = 1; i < n; i++) {
    if (a[i] == prefix[i - 1]) {
      flag = true;
    }
  }
  if (!flag) {
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  } else {
    sort(a.rbegin(), a.rend());
    if (a.front() == a.back()) {
      cout << "No\n";
    } else {
      swap(a[1], a.back());
      cout << "Yes\n";
      for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
      }
    }
  }
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
