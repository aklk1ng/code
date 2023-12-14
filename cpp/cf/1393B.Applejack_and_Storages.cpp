#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(1e5 + 5);
  int cnt2 = 0, cnt4 = 0;
  char op;
  int x;

  for (int i = 0; i < n; i++) {
    cin >> x;

    cnt2 -= cnt[x] / 2;
    cnt4 -= cnt[x] / 4;
    cnt[x]++;
    cnt2 += cnt[x] / 2;
    cnt4 += cnt[x] / 4;
  }
  int q;
  cin >> q;
  while (q--) {
    cin >> op >> x;

    cnt2 -= cnt[x] / 2;
    cnt4 -= cnt[x] / 4;
    if (op == '+') {
      cnt[x]++;
    } else {
      cnt[x]--;
    }
    cnt2 += cnt[x] / 2;
    cnt4 += cnt[x] / 4;

    if (cnt2 >= 4 && cnt4 >= 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
