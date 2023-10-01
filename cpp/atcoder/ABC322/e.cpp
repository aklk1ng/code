#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int N, K, P;
  cin >> N >> K >> P;
  vector<int> pw(K + 1);
  pw[0] = 1;
  for (int i = 1; i <= K; i++) {
    pw[i] = pw[i - 1] * (P + 1);
  }
  vector dp(pw[K], -1LL);
  dp[0] = 0;

  for (int i = 0; i < N; i++) {
    int C;
    cin >> C;

    vector<int> A(K);
    for (int j = 0; j < K; j++) {
      cin >> A[j];
    }
    for (int s = pw[K] - 1; s >= 0; s--) {
      int t = 0;
      for (int j = 0; j < K; j++) {
        int a = s / pw[j] % (P + 1);
        int na = min(P, a + A[j]);
        t += na * pw[j];
      }
      if (dp[s] != -1 && (dp[t] == -1 || dp[t] > dp[s] + C)) {
        dp[t] = dp[s] + C;
      }
    }
  }
  cout << dp.back() << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
