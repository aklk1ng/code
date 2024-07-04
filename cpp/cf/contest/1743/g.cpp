#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

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

int sub(int x, int y) { return add(x, mod - y); }

int expected(int mask) {
    if (mask & 2) {
        return 0;
    }
    return 1;
}

int last_bit(int x) {
    if (x == 0) {
        return -1;
    }
    return x - (x & (x - 1));
}

bool go(int &a, int x) {
    if (expected(a) != x) {
        a = 1 << x;
        return false;
    }
    a ^= (1 << x);
    while (true) {
        int b = last_bit(a);
        int c = last_bit(a - b);
        if (c == 2 * b) {
            a += b;
        } else {
            break;
        }
    }
    return true;
}

bool is_fib(int a) { return a == last_bit(a); }

auto go(const std::vector<std::pair<int, int>> &a,
                                    int x) {
    std::vector<std::pair<int, int>> nw;
    for (auto b : a) {
        int cost = b.first;
        int seqn = b.second;
        if (go(seqn, x)) {
            nw.push_back(std::make_pair(cost, seqn));
        }
    }
    return nw;
}

void solve() {
    int last = 1, sum = 1;
    std::vector<std::pair<int, int>> w;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (auto x : s) {
            int c = x - '0';
            int ndp = sub(sum, last);
            w = go(w, c);
            for (int j = 0; j < w.size(); j++) {
                if (is_fib(w[j].second)) {
                    ndp = sub(ndp, w[j].first);
                }
            }
            if (c == 1) {
                w.push_back(std::make_pair(last, 2));
            }
            sum = add(sum, ndp);
            last = ndp;
        }
        std::cout << last << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (false) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
