#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> bk(n + 1), a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= n) {
      bk[a[i]]++;
    }
  }
  set<int> st;
  for (int i = 0; i <= n; i++) {
    if (bk[i] == 0) {
      st.insert(i);
    }
  }

  while (q--) {
    int i, x;
    cin >> i >> x;
    i--;
    if (a[i] <= n) {
      bk[a[i]]--;
      if (bk[a[i]] == 0) {
        st.insert(a[i]);
      }
    }
    a[i] = x;
    if (a[i] <= n) {
      if (bk[a[i]] == 0) {
        st.erase(a[i]);
      }
      bk[a[i]]++;
    }
    cout << (*st.begin()) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
