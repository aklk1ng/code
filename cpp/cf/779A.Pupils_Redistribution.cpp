#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(6);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]--;
  }

  for (int i = 1; i <= 5; i++) {
    if (cnt[i] % 2) {
      cout << -1 << '\n';
      return;
    }
  }

  int sum = 0;
  for (auto &e : cnt) {
    sum += abs(e);
  }
  cout << sum / 4 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
