#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  priority_queue<int> pq;
  int x;
  for (int i = 0; i < 3; i++) {
    cin >> x;
    pq.push(x);
  }
  int ans = pq.top();
  pq.pop();
  int sum = 0;
  sum += pq.top();
  pq.pop();
  sum += pq.top();
  pq.pop();
  cout << (ans == sum ? "Yes\n" : "No\n");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
