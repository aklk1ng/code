#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 1e6;
int n, k;
std::vector<int> a;
std::vector<int> primes_x[N + 1];
std::unordered_map<int, int> last_ind_p;
std::vector<bool> is_prime(N + 1, true);
std::vector<int> primes;
std::vector<int> p, sz, p_rs;

int col(int A) { return (A == p[A] ? A : p[A] = col(p[A])); }

void unique(int A, int B) {
    A = col(A);
    B = col(B);
    if (A == B) {
        return;
    }
    if (sz[A] < sz[B]) {
        std::swap(A, B);
    }
    p[B] = A;
    sz[A] += sz[B];
}

void init() {
    for (ll i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    std::cin >> n >> k;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    last_ind_p.clear();
    std::vector<int> aa;
    for (int i = 1; i < n; i++) {
        aa.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        aa.push_back(a[i]);
    }
    a = aa;
    int n2 = n;
    n = a.size();
    p.assign(n, -1);
    p_rs.assign(n, -1);
    sz.assign(n, -1);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n2; i++) {
        p_rs[i] = i + 1;
        p_rs[2 * n2 - 2 - i] = i + 1;
    }
    std::vector<int> a2 = a;
    std::sort(a2.begin(), a2.end());
    a2.resize(std::unique(a2.begin(), a2.end()) - a2.begin());
    std::unordered_set<int> to_clean;
    for (int elem : a2) {
        int cur_elem = elem;
        for (ll p : primes) {
            if (p * p > elem) {
                break;
            }
            if (elem % p == 0) {
                primes_x[cur_elem].push_back(p);
                if (primes_x[cur_elem].size() == 1) {
                    to_clean.insert(cur_elem);
                }
            }
            while (elem % p == 0) {
                elem /= p;
            }
        }
        if (elem > 1) {
            primes_x[cur_elem].push_back(elem);
            if (primes_x[cur_elem].size() == 1) {
                to_clean.insert(cur_elem);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int cur_p : primes_x[a[i]]) {
            if (last_ind_p.count(cur_p) && i - last_ind_p[cur_p] <= k) {
                unique(last_ind_p[cur_p], i);
            }
            last_ind_p[cur_p] = i;
        }
    }
    for (int i : to_clean) {
        primes_x[i].clear();
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == i) {
            if (a[i] > 1) {
                ans += 1;
            } else {
                ans += p_rs[i];
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    init();
    while (T--) {
        solve();
    }

    return 0;
}
