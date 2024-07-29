#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 2e5 + 5;
std::bitset<N> isComposite, isWin, isPrimeLosing, isPrimeWin, isGood;

void init() {
    isComposite[1] = true;
    for (int i = 2; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += i) {
            isComposite[j] = true;
        }
    }
    for (int i = 3; i <= N; i += 2) {
        int count = 0, j = i;
        while (!isComposite[j - 2]) {
            count++;
            j -= 2;
        }
        isWin[i] = count % 2;
        isPrimeLosing[i] = !isComposite[i] && !isWin[i];
    }
    isWin[4] = true;
    for (int i = 3; i <= N; i += 2) {
        if (isPrimeLosing[i]) {
            isWin |= isPrimeLosing << i;
        }
    }
    for (int i = 1; i <= N; ++i) {
        isPrimeWin[i] = (i % 2) && isWin[i] && !isComposite[i];
    }
    for (int i = 3; i <= N; i += 2) {
        if (isPrimeWin[i]) {
            isGood |= isPrimeWin << i;
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    int totWin = 0, totGood = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        totWin += isWin[x];
        totGood += isGood[x];
    }
    if (totWin <= n - n % 2) {
        std::cout << (totWin ? "Alice" : "Bob") << std::endl;
    } else {
        std::cout << (totGood && totGood < n ? "Alice" : "Bob") << std::endl;
    }
}

int main() {
    init();
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
