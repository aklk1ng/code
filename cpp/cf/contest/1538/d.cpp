#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 5e5 + 5;
bool isPrime[N];
std::vector<int> primes;

void init() {
    std::fill(isPrime + 2, isPrime + N, true);
    for (int i = 2; i * i < N; i++) {
        for (int j = i * i; j < N; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int calcPrime(int n) {
    int res = 0;
    for (int i : primes) {
        if (i * i > n) {
            break;
        }
        while (n % i == 0) {
            n /= i;
            res++;
        }
    }
    if (n > 1) {
        res++;
    }
    return res;
}

std::map<int, int> decompose(int n) {
    std::map<int, int> a;
    for (int i : primes) {
        if (i * i > n) {
            break;
        }
        int p = 0;
        while (n % i == 0) {
            n /= i;
            p++;
        }
        if (p > 0) {
            a[i] = p;
        }
    }
    if (n > 1) {
        a[n] = 1;
    }
    return a;
}

bool check(const std::map<int, int> &divs,
           std::map<int, int>::const_iterator it, std::map<int, int> &divsA,
           std::map<int, int> &divsB, int low, int high, int k) {
    if (it == divs.end()) {
        return __builtin_popcount(low) <= k && k <= high;
    }
    for (int p = 0; p <= it->second; p++) {
        int pa = divsA[it->first];
        int pb = divsB[it->first];
        int nextLow = low;
        if (p != pa) {
            nextLow |= 1;
        }
        if (p != pb) {
            nextLow |= 2;
        }
        if (check(divs, next(it), divsA, divsB, nextLow, high + pa + pb - 2 * p,
                  k)) {
            return true;
        }
    }
    return false;
}

void solve() {
    int a, b, k;
    std::cin >> a >> b >> k;
    int g = std::__gcd(a, b);
    int low = 0;
    int high = 0;
    {
        int t;
        int ta = 1;
        while ((t = std::__gcd(a, g)) != 1) {
            a /= t;
            ta *= t;
        }
        high += calcPrime(a);
        if (a != 1) {
            low |= 1;
        }
        a = ta;
    }
    {
        int t;
        int tb = 1;
        while ((t = std::__gcd(b, g)) != 1) {
            b /= t;
            tb *= t;
        }
        high += calcPrime(b);
        if (b != 1) {
            low |= 2;
        }
        b = tb;
    }
    auto divs = decompose(g);
    auto divsA = decompose(a);
    auto divsB = decompose(b);
    std::cout << (check(divs, divs.begin(), divsA, divsB, low, high, k) ? "YES"
                                                                        : "NO")
              << '\n';
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
