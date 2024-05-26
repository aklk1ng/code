#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

struct ch {
    std::string c;

    ch() { c = ""; }

    ch(std::string cc) { c = cc; }

    bool operator==(const ch &p) const { return c == p.c; }

    bool operator!=(const ch &p) const { return c != p.c; }

    void add(ch &p) { c.append(p.c); }
};

std::vector<ch> cal(std::vector<ch> cs) {
    int n = cs.size();
    int t = 0;
    if (cs.empty()) {
        return cs;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (cs[i] != cs[n - 1]) {
            break;
        }
        t++;
    }
    if (t == 0) {
        std::vector<ch> res;
        res.push_back(cs[n - 1]);
        return res;
    }
    int p = n - (t + 1);
    if (p <= t) {
        std::vector<ch> res;
        std::vector<ch> nxt;
        int k = (t + 1) / (p + 1);
        int le = (t + 1) % (p + 1);
        ch m = cs[n - 1];
        for (int j = 1; j < k; j++) {
            m.add(cs[n - 1]);
        }
        for (int i = 0; i < p; i++) {
            ch tmp = m;
            tmp.add(cs[i]);
            nxt.push_back(tmp);
        }
        for (int i = 0; i < le; i++) {
            nxt.push_back(cs[n - 1]);
        }
        auto nxt_solved = cal(nxt);
        for (auto i : nxt_solved) {
            res.push_back(i);
        }
        res.push_back(m);
        return res;
    } else {
        std::vector<ch> res;
        std::vector<ch> nxt;
        ch m = cs[n - 1];
        for (int i = 0; i < t; i++) {
            nxt.push_back(m);
        }
        int now = 0, beg = 0;
        for (int i = 0; i < p; i++) {
            nxt[now].add(cs[i]);
            if (now >= 1) {
                if (cs[i] != cs[i - 1]) {
                    beg = now;
                }
            }
            now++;
            if (now >= t) {
                now = beg;
            }
        }
        auto nxt_solved = cal(nxt);
        for (auto i : nxt_solved) {
            res.push_back(i);
        }
        res.push_back(m);
        return res;
    }
}

std::vector<ch> trans(std::string s) {
    std::vector<ch> tmp;
    for (auto i : s) {
        std::string t = "";
        t += i;
        tmp.push_back(t);
    }
    return tmp;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::sort(s.begin(), s.end());
    auto tmp = trans(s);
    auto ans = cal(tmp);
    for (auto c : ans) {
        std::cout << c.c;
    }
    std::cout << "\n";
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
