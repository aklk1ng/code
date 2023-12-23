#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int l;
  cin >> l;
  stack<ll> st;
  st.push(1);

  ll ans = 0;
  for (int i = 0; i < l; i++) {
    string t;
    cin >> t;
    if (t == "for") {
      int x;
      cin >> x;
      st.push(min(1ll << 32, st.top() * x));
    } else if (t == "end") {
      st.pop();
    } else {
      ans += st.top();
    }
  }
  if (ans >= 1ll << 32) {
    cout << "OVERFLOW!!!" << '\n';
  } else {
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
