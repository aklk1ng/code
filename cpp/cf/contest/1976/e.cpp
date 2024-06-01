#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 3e5 + 5;

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

int nxt[N], prv[N];
bool exists[N];

void solve() {
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        nxt[i] = prv[i] = -1;
    }
    exists[n] = true;
    std::vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) {
        std::cin >> l[i];
    }
    for (int i = 0; i < q; i++) {
        std::cin >> r[i];
    }

    for (int i = 0; i < q; i++) {
        int L = l[i], R = r[i];
        if (exists[L]) {
            exists[R] = true;
            nxt[R] = nxt[L];
            if (nxt[R] != -1) {
                prv[nxt[R]] = R;
            }
            prv[R] = L;
            nxt[L] = R;
        } else {
            exists[L] = true;
            prv[L] = prv[R];
            if (prv[L] != -1) {
                nxt[prv[L]] = L;
            }
            nxt[L] = R;
            prv[R] = L;
        }
    }
    std::vector<int> seq;
    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (prv[i] == -1 && exists[i]) {
            start = i;
        }
    }
    seq.push_back(start);
    while (nxt[start] != -1) {
        start = nxt[start];
        seq.push_back(start);
    }
    std::vector<int> cnt_segments(n + 1);
    cnt_segments[seq[0]]++;
    cnt_segments[seq[q]]++;
    for (int i = 0; i < q; i++) {
        cnt_segments[std::max(seq[i], seq[i + 1])]++;
    }
    int ans = 1;
    int places = 0;
    for (int i = n; i >= 1; i--) {
        if (exists[i]) {
            places += cnt_segments[i];
        } else {
            ans = mul(ans, places);
            places++;
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
