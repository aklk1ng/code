#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 5e5 + 13;
const int A = 1e6 + 13;

std::vector<int> divs[A];
int a[N];

int gr_lf[N], gr_rg[N];
int le_lf[N], le_rg[N];

std::vector<int> pos[A];
int ind[A];

void init() {
    for (int i = 1; i < A; i++) {
        for (int j = i; j < A; j += i) {
            divs[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pos[a[i]].push_back(i);
    }

    {
        std::stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] < a[i]) {
                st.pop();
            }

            gr_lf[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
    }

    {
        std::stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] <= a[i]) {
                st.pop();
            }

            gr_rg[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
    }

    {
        std::stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }

            le_lf[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
    }

    {
        std::stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }

            le_rg[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int x : divs[a[i]]) {
            if (ind[x] >= 1) {
                int j = pos[x][ind[x] - 1];
                if (j > gr_lf[i] && le_rg[j] > i) {
                    ans += (j - std::max(gr_lf[i], le_lf[j])) * 1ll *
                           (std::min(gr_rg[i], le_rg[j]) - i);
                }
            }

            if (ind[x] < pos[x].size()) {
                int j = pos[x][ind[x]];
                if (j < gr_rg[i] && le_lf[j] < i) {
                    ans += (i -
                            std::max({gr_lf[i], le_lf[j],
                                      ind[x] >= 1 ? pos[x][ind[x] - 1] : -1})) *
                           1ll * (std::min(gr_rg[i], le_rg[j]) - j);
                }
            }
        }

        ind[a[i]]++;
    }

    std::cout << ans << '\n';

    for (int i = 0; i < n; i++) {
        pos[a[i]].erase(pos[a[i]].begin(), pos[a[i]].end());
        gr_lf[i] = gr_rg[i] = le_lf[i] = le_rg[i] = 0;
        ind[a[i]] = 0;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    init();
    while (_--) {
        solve();
    }

    return 0;
}
