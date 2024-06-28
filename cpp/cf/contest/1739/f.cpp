#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 10043;
const int K = 12;

int tsz = 0;
int trie[N][K];
int aut[N][K];
int lnk[N];
int p[N];
int pchar[N];
int cost[N];
int ncost[N];

int newNode() {
    lnk[tsz] = -1;
    ncost[tsz] = -1;
    cost[tsz] = 0;
    for (int i = 0; i < K; i++) {
        trie[tsz][i] = aut[tsz][i] = -1;
    }
    return tsz++;
}

int nxt(int x, int y) {
    if (trie[x][y] == -1) {
        trie[x][y] = newNode();
        pchar[trie[x][y]] = y;
        p[trie[x][y]] = x;
    }
    return trie[x][y];
}

int go(int x, int y);

int get_lnk(int x) {
    if (lnk[x] != -1) {
        return lnk[x];
    }
    int &d = lnk[x];
    if (x == 0 || p[x] == 0) {
        return d = 0;
    }
    return d = go(get_lnk(p[x]), pchar[x]);
}

int go(int x, int y) {
    if (aut[x][y] != -1) {
        return aut[x][y];
    }
    int &d = aut[x][y];
    if (trie[x][y] != -1) {
        return d = trie[x][y];
    }
    if (x == 0) {
        return d = 0;
    }
    return d = go(get_lnk(x), y);
}

void add(std::string s, int c) {
    int cur = 0;
    for (auto x : s) {
        cur = nxt(cur, x - 'a');
    }
    cost[cur] += c;
}

int calc(int x) {
    if (ncost[x] != -1) {
        return ncost[x];
    }
    ncost[x] = cost[x];
    int y = get_lnk(x);
    if (y != x) {
        ncost[x] += calc(y);
    }
    return ncost[x];
}

void solve() {
    int root = newNode();
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string s;
        int x;
        std::cin >> x >> s;
        std::map<char, std::set<char>> adj;
        for (int j = 0; j + 1 < s.size(); j++) {
            adj[s[j]].insert(s[j + 1]);
            adj[s[j + 1]].insert(s[j]);
        }
        bool bad = false;
        std::string res = "";
        char c;
        for (c = 'a'; c <= 'l'; c++) {
            if (!adj.count(c)) {
                continue;
            }
            if (adj[c].size() >= 3) {
                bad = true;
            }
            if (adj[c].size() == 1) {
                break;
            }
        }
        if (c == 'm' || bad) {
            continue;
        }
        res.push_back(c);
        while (adj[c].size() > 0) {
            char d = *adj[c].begin();
            adj[c].erase(d);
            adj[d].erase(c);
            c = d;
            res.push_back(c);
        }
        bad |= adj.size() != res.size();
        std::map<char, int> pos;
        for (int i = 0; i < res.size(); i++) {
            pos[res[i]] = i;
        }
        for (int i = 0; i + 1 < s.size(); i++) {
            bad |= abs(pos[s[i]] - pos[s[i + 1]]) > 1;
        }
        if (bad) {
            continue;
        }
        add(res, x);
        reverse(res.begin(), res.end());
        add(res, x);
    }
    int INF = 1e9;
    int K = 12;
    std::vector<std::vector<int>> dp(1 << K, std::vector<int>(tsz + 1, -INF));
    std::vector<std::vector<std::pair<int, int>>> pdp(
        1 << K, std::vector<std::pair<int, int>>(tsz + 1));
    dp[0][0] = 0;
    for (int i = 0; i < (1 << K); i++)
        for (int j = 0; j <= tsz; j++) {
            for (int z = 0; z < K; z++) {
                if (i & (1 << z)) {
                    continue;
                }
                int nstate = go(j, z);
                int add = calc(nstate);
                int nmask = i | (1 << z);
                if (dp[nmask][nstate] < dp[i][j] + add) {
                    dp[nmask][nstate] = dp[i][j] + add;
                    pdp[nmask][nstate] = {z, j};
                }
            }
        }
    std::string ans = "";
    int curmask = (1 << K) - 1;
    int curstate = std::max_element(dp[curmask].begin(), dp[curmask].end()) -
                   dp[curmask].begin();
    while (curmask != 0) {
        int cc = pdp[curmask][curstate].first;
        int ns = pdp[curmask][curstate].second;
        ans.push_back(char('a' + cc));
        curmask ^= (1 << cc);
        curstate = ns;
    }
    std::cout << ans << '\n';
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
