#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  vector<string> s(n);
  vector<int> score(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < n; j++) {
      if (s[j] == "o") {
        score[i] += a[j];
      }
    }
    score[i] += i + 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
