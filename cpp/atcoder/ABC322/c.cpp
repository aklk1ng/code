#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M + 1);
  for (int i = 1; i <= M; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= N; i++) {
    int need = lower_bound(A.begin(), A.end(), i) - A.begin();
    cout << A[need] - i << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
