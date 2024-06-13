#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int n, m, minR, maxR, minC, maxC, sz, ans;
std::vector<int> R, C, freeR, freeC;
std::vector<std::vector<int>> RC;
std::vector<std::vector<bool>> vis;
std::vector<std::vector<char>> A;

void dfs(int i, int j) {
    if (i <= 0 or i > n or j <= 0 or j > m or vis[i][j] or A[i][j] == '.') {
        return;
    }

    vis[i][j] = true;

    sz++;
    minR = std::min(minR, i);
    maxR = std::max(maxR, i);
    minC = std::min(minC, j);
    maxC = std::max(maxC, j);

    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

void solve() {
    std::cin >> n >> m;

    R.assign(n + 5, 0);
    C.assign(m + 5, 0);
    freeR.assign(n + 5, 0);
    freeC.assign(m + 5, 0);
    RC.assign(n + 5, std::vector<int>(m + 5, 0));
    vis.assign(n + 5, std::vector<bool>(m + 5, false));
    A.assign(n + 5, std::vector<char>(m + 5, ' '));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> A[i][j];

            if (A[i][j] == '.') {
                freeR[i]++;
                freeC[j]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] or A[i][j] == '.')
                continue;

            sz = 0;
            minR = 1e9;
            maxR = -1e9;
            minC = 1e9;
            maxC = -1e9;

            dfs(i, j);

            minR = std::max(minR - 1, 1);
            maxR = std::min(maxR + 1, n);
            minC = std::max(minC - 1, 1);
            maxC = std::min(maxC + 1, m);

            R[minR] += sz;
            R[maxR + 1] -= sz;

            C[minC] += sz;
            C[maxC + 1] -= sz;

            RC[minR][minC] += sz;
            RC[maxR + 1][minC] -= sz;
            RC[minR][maxC + 1] -= sz;
            RC[maxR + 1][maxC + 1] += sz;
        }
    }

    for (int i = 1; i <= n; i++) {
        R[i] += R[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        C[i] += C[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            RC[i][j] += RC[i - 1][j] + RC[i][j - 1] - RC[i - 1][j - 1];
        }
    }

    ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = std::max(ans, (R[i] + C[j] - RC[i][j]) +
                                    (freeR[i] + freeC[j] - (A[i][j] == '.')));
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
