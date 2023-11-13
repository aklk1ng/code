#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string s;
  cin >> s;
  string st;
  for (auto &c : s) {
    st += c;
    if ((int)st.size() >= 3 && st.substr((int)st.size() - 3) == "ABC") {
      st.erase(st.end() - 3, st.end());
    }
  }
  cout << st << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
