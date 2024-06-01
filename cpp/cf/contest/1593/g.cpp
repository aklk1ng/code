#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 1'000'000;

int Odd[N + 1];
int Even[N + 1];

void solve() {

    std::string s;
    int q;
    std::cin >> s >> q;
    int n = s.length();

    Odd[0] = Even[0] = 0;
    for (int i = 0; i < n; i++) {
        Odd[i + 1] = Odd[i];
        Even[i + 1] = Even[i];

        if (s[i] == '[' || s[i] == ']') {
            if (i & 1) {
                Odd[i + 1]++;
            } else {
                Even[i + 1]++;
            }
        }
    }

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--;
        int odd = Odd[r] - Odd[l];
        int even = Even[r] - Even[l];
        std::cout << std::abs(odd - even) << '\n';
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
