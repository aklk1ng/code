#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    std::cout << "? aa" << std::endl;
    int p, v[10];
    std::cin >> p;
    p--;
    std::cout << "? zzzzzzzzzz" << std::endl;
    int hsh, hsho;
    ll nom = 0, cnt = 1;
    std::cin >> hsh;
    hsho = hsh;
    hsh++;
    for (int i = 0; i < 10; i++) {
        nom += 26 * cnt;
        cnt *= p;
        v[i] = 26 - (hsh % p);
        hsh /= p;
    }
    std::string s;
    cnt = 1;
    ll ch = 0;
    for (int i = 0; i < 10; i++) {
        if (v[i] < 1) {
            v[i] = 26;
            v[i + 1]--;
        }
        ch += cnt * v[i];
        cnt *= p;
        s += 'a' + (v[i] - 1);
    }
    std::cout << "? " << s << std::endl;
    int ans;
    std::cin >> ans;
    std::cout << "! " << p << ' ' << ans + nom - ch - hsho << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
