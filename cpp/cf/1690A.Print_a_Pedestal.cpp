#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  int h1, h2, h3;
  h1 = n / 3;
  h2 = n / 3 + n % 3;
  h3 = n / 3;
  while (!((h2 > h1) && (h1 > h3))) {
    if (h1 == h2 && h3 > 1) {
      h3--;
      h2++;
    } else if (h1 == h2 && h3 == 1) {
      h1--;
      h2++;
    }
    if (h3 == h1) {
      h3--;
      h1++;
    }
  }
  cout << h1 << ' ' << h2 << ' ' << h3 << '\n';
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
