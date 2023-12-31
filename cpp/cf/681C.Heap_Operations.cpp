#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<pair<string, int>> ans;
  priority_queue<int> q;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "insert") {
      int x;
      cin >> x;
      q.push(-x);
      ans.push_back({s, x});
    } else if (s == "getMin") {
      int x;
      cin >> x;
      while (!q.empty() && -q.top() < x) {
        q.pop();
        ans.push_back({"removeMin", 2e9});
      }
      if (q.empty() || -q.top() > x) {
        q.push(-x);
        ans.push_back({"insert", x});
      }
      ans.push_back({s, x});
    } else {
      if (q.empty()) {
        ans.push_back({"insert", 0});
      } else {
        q.pop();
      }
      ans.push_back({s, 2e9});
    }
  }
  cout << ans.size() << '\n';
  for (auto &e : ans) {
    cout << e.first;
    if (e.second != 2e9) {
      cout << ' ' << e.second;
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
