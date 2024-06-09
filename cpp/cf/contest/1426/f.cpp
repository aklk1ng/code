#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
const int N = 200043;
const int K = 4;

int add(int x, int y) {
    x += y;
    while (x >= mod) {
        x -= mod;
    }
    while (x < 0) {
        x += mod;
    }
    return x;
}

int mul(int x, int y) { return (x * 1ll * y) % mod; }

int n;
std::string s;
int dp[N][K][K];
char buf[N];
int pow3[N];

void solve() {
    std::cin >> n;
    std::cin >> buf;
    s = buf;
    int cntQ = 0;
    for (auto c : s) {
        if (c == '?') {
            cntQ++;
        }
    }
    pow3[0] = 1;
    for (int i = 1; i < N; i++) {
        pow3[i] = mul(pow3[i - 1], 3);
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 3; j++) {
            for (int k = 0; k <= 3; k++) {
                if (!dp[i][j][k]) {
                    continue;
                }
                dp[i + 1][j][k] = add(dp[i + 1][j][k], dp[i][j][k]);
                if (j < 3 && (s[i] == '?' || s[i] - 'a' == j)) {
                    int nk = (s[i] == '?' ? k + 1 : k);
                    dp[i + 1][j + 1][nk] =
                        add(dp[i + 1][j + 1][nk], dp[i][j][k]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 3; i++) {
        if (cntQ >= i) {
            ans = add(ans, mul(dp[n][3][i], pow3[cntQ - i]));
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
