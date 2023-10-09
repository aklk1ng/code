#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> odd;
  vector<int> even;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] & 1) {
      odd.push_back(i + 1);
    } else {
      even.push_back(i + 1);
    }
  }
  if ((int)odd.size() >= 1 && (int)even.size() >= 2) {
    cout << "Yes\n";
    cout << odd[0] << ' ' << even[0] << ' ' << even[1] << '\n';
  } else if ((int)odd.size() >= 3) {
    cout << "Yes\n";
    cout << odd[0] << ' ' << odd[1] << ' ' << odd[2] << '\n';
  } else {
    cout << "No\n";
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
