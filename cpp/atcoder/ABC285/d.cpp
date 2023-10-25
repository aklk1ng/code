#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  map<string, string> m;
  set<string> st;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    m[a] = b;
    st.insert(a);
  }

  set<string> vis;
  for (auto &name : st) {
    string nx = m[name];
    while (!vis.count(nx)) {
      vis.insert(nx); 
      nx = m[nx];
      if (nx == name) {
        cout << "No\n"; 
        return;
      }
    }
  }
  cout << "Yes\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
