#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

bool ask(int i, int j) {
    std::cout << "? " << j << ' ' << i << std::endl;
    std::string resp;
    std::cin >> resp;
    if (resp == "-1") {
        assert(false);
    }
    if (resp == "YES") {
        return true;
    } else {
        return false;
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> st, st2, st3;
    st = {1};
    for (int i = 2; i <= n; i++) {
        if (st2.empty()) {
            if (ask(i, st.back())) {
                st.push_back(i);
            } else {
                st2.push_back(i);
            }
        } else if (st3.empty()) {
            int ok1 = ask(i, st.back()), ok2 = ask(i, st2.back());
            if (ok1 && ok2) {
                st3.push_back(i);
            } else if (ok1) {
                st.push_back(i);
            } else if (ok2) {
                st2.push_back(i);
            } else {
                assert(false);
            }
        } else {
            if (ask(i, st3.back())) {
                st3.push_back(i);
            } else {
                if (ask(i, st.back())) {
                    st.push_back(i);
                    for (auto j : st3) {
                        st2.push_back(j);
                    }
                    st3.clear();
                } else {
                    st2.push_back(i);
                    for (auto j : st3) {
                        st.push_back(j);
                    }
                    st3.clear();
                }
            }
        }
    }
    if (!st3.empty()) {
        for (auto i : st3) {
            st.push_back(i);
        }
        st3.clear();
    }
    std::vector<int> colors(n + 1);
    for (auto i : st2) {
        colors[i] = 1;
    }
    std::cout << "! ";
    for (int i = 1; i <= n; i++) {
        std::cout << colors[i] << ' ';
    }
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
