#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    cnt[i] = count(s.begin(), s.end(), 'o');
  }
  vector<int> ans(n);
  iota(ans.begin(), ans.end(), 0);
  sort(ans.begin(), ans.end(),
       [&](int i, int j) { return cnt[i] != cnt[j] ? cnt[i] > cnt[j] : i < j; });
  for (auto &i : ans) {
    cout << i + 1 << " \n"[i == ans.back()];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
