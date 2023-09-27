#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  string s;
  set<char> a;
  getline(cin, s);
  for (auto &ch : s) {
    if (ch >= 'a' && ch <= 'z') {
      a.insert(ch);
    }
  }
  cout << a.size() << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
