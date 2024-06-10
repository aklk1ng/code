#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

bool sorted(std::vector<int> arr, int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

bool cyclic(std::vector<int> arr, int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] % n != (arr[i - 1] + 1) % n) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    if (sorted(arr, n)) {
        std::cout << n << "\n0\n";
        return;
    }
    if (cyclic(arr, n)) {
        std::cout << n - 1 << '\n';
        int pos;
        for (pos = 0; pos < n; ++pos) {
            if (arr[pos] == 1) {
                break;
            }
        }
        std::cout << pos << '\n';
        for (int i = 0; i < pos; ++i) {
            std::cout << "2 1\n";
        }
        return;
    }
    std::vector<std::pair<int, int>> ops;
    if (n % 2 == 0) {
        int inv = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] > arr[j]) {
                    ++inv;
                }
            }
        }
        if (inv & 1) {
            int pos;
            for (pos = 0; pos < n; ++pos) {
                if (arr[pos] == n) {
                    break;
                }
            }
            if (pos < 3) {
                for (int i = 0; i <= pos; ++i) {
                    ops.push_back({2, 1});
                }
                std::vector<int> tmp = arr;
                for (int i = 0; i < n - 2; ++i) {
                    arr[i] = tmp[(i + pos + 1) % (n - 2)];
                }
            }
            for (pos = 0; pos < n; ++pos) {
                if (arr[pos] == n) {
                    break;
                }
            }
            for (int i = pos; i < n - 1; ++i) {
                ops.push_back({3, 4});
            }
            std::vector<int> tmp = arr;
            for (int i = 2; i < n; ++i) {
                arr[i] = tmp[((i + pos - 3) % (n - 2)) + 2];
            }
            --n;
        }
    }
    std::cout << n - 2 << '\n';
    int div = 0;
    for (int i = n; i > 0; --i) {
        int pos;
        for (pos = 0; pos < n; ++pos) {
            if (arr[pos] == i) {
                break;
            }
        }
        pos += 1;
        if (pos == i) {
            continue;
        }
        if (div % 2 != pos % 2) {
            if (n & 1) {
                while (div < n) {
                    ops.push_back({3, 1});
                    div += 2;
                }
                div %= n;
            } else {
                while (div != pos - 1) {
                    if (div < pos - 1) {
                        ops.push_back({3, 1});
                        div += 2;
                    } else {
                        ops.push_back({1, 3});
                        div -= 2;
                    }
                }
                if (pos > 1) {
                    ops.push_back({2, 3});
                    std::swap(arr[(div + n - 1) % n], arr[div]);
                    div = (div + n - 1) % n;
                    --pos;
                }
                ops.push_back({3, 1});
                div += 2;
                ops.push_back({2, 3});
                std::swap(arr[(div + n - 1) % n], arr[div]);
                div = (div + n - 1) % n;
            }
        }
        while (div != pos) {
            if (div < pos) {
                ops.push_back({3, 1});
                div += 2;
            } else {
                ops.push_back({1, 3});
                div -= 2;
            }
        }
        for (int j = pos; j < i; ++j) {
            ops.push_back({2, 1});
            std::swap(arr[div - 1], arr[div]);
            ++div;
        }
    }
    if (div % 2 == 1) {
        while (div < n) {
            ops.push_back({3, 1});
            div += 2;
        }
        div %= n;
    }
    while (div > 0) {
        ops.push_back({1, 3});
        div -= 2;
    }
    std::cout << ops.size() << '\n';
    for (std::pair<int, int> p : ops) {
        std::cout << p.first << ' ' << p.second << '\n';
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
