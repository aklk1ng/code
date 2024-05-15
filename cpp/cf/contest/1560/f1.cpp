#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::string cal1(std::string n) {
    std::string res(n.length(), '9');
    for (char c = '8'; c >= '0'; c--) {
        std::string t(n.length(), c);
        if (t >= n) {
            res = t;
        }
    }

    return res;
}

std::string cal2(std::string n) {
    std::string res = cal1(n);

    for (char a = '0'; a <= '9'; a++)
        for (char b = a + 1; b <= '9'; b++) {
            bool n_ok = true;
            for (int i = 0; i < n.length(); i++) {
                if (n[i] < b) {
                    std::string t = n;
                    if (t[i] < a) {
                        t[i] = a;
                    } else {
                        t[i] = b;
                    }
                    for (int j = i + 1; j < n.length(); j++)
                        t[j] = a;
                    if (res > t) {
                        res = t;
                    }
                }

                if (n[i] != a && n[i] != b) {
                    n_ok = false;
                    break;
                }
            }

            if (n_ok) {
                return n;
            }
        }

    return res;
}

void solve() {
    std::string n;
    int k;
    std::cin >> n >> k;

    if (k == 1) {
        std::cout << cal1(n) << '\n';
    } else {
        std::cout << cal2(n) << '\n';
    }
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
