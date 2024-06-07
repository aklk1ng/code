#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::pair<int, int> ask(int d) {
    std::cout << "? " << d << std::endl;
    int v, u;
    std::cin >> v >> u;
    return {v, u};
}

std::pair<int, int> get(int n, std::vector<int> &nxt) {
    if (n == 1) {
        int v = ask(0).first;
        return {v, v};
    }
    if (n == 2) {
        int u = ask(0).first;
        int v = ask(0).first;
        nxt[u] = v;
        return {u, v};
    }
    std::pair<int, int> t = ask(n - 2);
    int v = t.first;
    int ban = t.second;
    if (ban != 0) {
        std::pair<int, int> res = get(n - 1, nxt);
        if (ban != res.first) {
            nxt[v] = res.first;
            return {v, res.second};
        } else {
            nxt[res.second] = v;
            return {res.first, v};
        }
    } else {
        int u = ask(0).first;
        nxt[u] = v;
        std::pair<int, int> res = get(n - 2, nxt);
        nxt[v] = res.first;
        return {u, res.second};
    }
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> nxt(n + 1, -1);
    std::pair<int, int> ans = get(n, nxt);

    int v = ans.first;
    std::cout << "! ";
    do {
        std::cout << v << " ";
        v = nxt[v];
    } while (v != -1);
    std::cout << std::endl;
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
