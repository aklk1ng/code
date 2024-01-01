#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> cnt(3), cur(3, n / 3);
  for (auto &c : s) {
    cnt[c - '0']++;
  }
  auto cal = [&]() {
    int res = 0;
    for (int i = 0; i < 3; i++) {
      res += abs(cnt[i] - cur[i]);
    }
    return res / 2;
  };
  int need = cal();
  int t = 0;
  for (int i = 0; i < n; i++) {
    cnt[s[i] - '0']--;
    for (int j = 0; j < 3; j++) {
      if (cur[j] == 0) {
        continue;
      }
      int rep = j != s[i] - '0';
      cur[j]--;
      if (t + rep + cal() == need) {
        s[i] = j + '0';
        t += rep;
        break;
      }
      cur[j]++;
    }
  }
  cout << s << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
