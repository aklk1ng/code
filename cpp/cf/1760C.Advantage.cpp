#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int best = *max_element(s.begin(), s.end());
  vector<int> tmp(s);
  sort(tmp.rbegin(), tmp.rend());
  int se = tmp[1];
  for (auto &i : s) {
    if (i != best) {
      cout << i - best << ' ';
    } else {
      cout << i - se << ' ';
    }
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
