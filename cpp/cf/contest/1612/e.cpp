#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 200043;
const int K = 20;
std::vector<int> idx[N];
int m[N], k[N];

bool frac_greater(std::pair<int, int> a, std::pair<int, int> b) {
    return a.first * b.second > a.second * b.first;
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> m[i] >> k[i];
        idx[m[i]].push_back(i);
    }

    std::vector<int> cert;
    std::pair<int, int> ans = {0, 1};
    for (int i = 1; i <= K; i++) {
        std::vector<int> score(N);
        for (int j = 0; j < n; j++) {
            score[m[j]] += std::min(i, k[j]);
        }
        std::vector<std::pair<int, int>> aux;
        for (int j = 0; j < N; j++) {
            aux.push_back(std::make_pair(score[j], j));
        }
        std::sort(aux.rbegin(), aux.rend());
        std::pair<int, int> cur_ans = {0, i};
        std::vector<int> cur_cert;
        for (int j = 0; j < i; j++) {
            cur_ans.first += aux[j].first;
            cur_cert.push_back(aux[j].second);
        }
        if (frac_greater(cur_ans, ans)) {
            ans = cur_ans;
            cert = cur_cert;
        }
    }
    std::cout << cert.size() << '\n';
    std::shuffle(cert.begin(), cert.end(), std::mt19937(time(NULL)));
    for (auto x : cert) {
        std::cout << x << " ";
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (false) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
