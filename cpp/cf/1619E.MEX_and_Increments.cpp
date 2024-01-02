#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), cnt(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a.begin(), a.end());
  stack<int> st;
  vector<ll> ans(n + 1, -1);
  ll sum = 0;
  for (int i = 0; i <= n; i++) {
    if (i > 0 && cnt[i - 1] == 0) {
      if (st.empty()) {
        break;
      }
      int j = st.top();
      st.pop();
      sum += i - j - 1;
    }
    ans[i] = sum + cnt[i];
    while (i > 0 && cnt[i - 1] > 1) {
      cnt[i - 1]--;
      st.push(i - 1);
    }
  }

  for (auto &e : ans) {
    cout << e << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
