#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int inversions(int arr[], int l, int r) {
    if (r == l) {
        return 0;
    }

    int mid = (l + r) / 2;
    int x = inversions(arr, l, mid);
    int y = inversions(arr, mid + 1, r);
    int ans[r - l + 1];
    int curr = 0, inv = 0;
    int pointx = l, pointy = mid + 1;

    while (pointx <= mid && pointy <= r) {
        if (arr[pointx] < arr[pointy]) {
            inv += pointy - mid - 1;
            ans[curr] = arr[pointx];

            pointx++;
        } else {
            ans[curr] = arr[pointy];
            pointy++;
        }

        curr++;
    }
    while (pointx <= mid) {
        inv += pointy - mid - 1;
        ans[curr] = arr[pointx];
        pointx++;
        curr++;
    }
    while (pointy <= r) {
        ans[curr] = arr[pointy];
        pointy++;
        curr++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = ans[i - l];
    }
    return x + y + inv;
}

void solve() {
    int n;
    std::cin >> n;
    int a[n], b[n], x[n], y[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        x[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        y[i] = b[i];
    }

    std::sort(x, x + n);
    std::sort(y, y + n);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] != y[i]) {
            flag = 1;
        }
    }

    std::cout << (((inversions(a, 0, n - 1) % 2) ==
                   (inversions(b, 0, n - 1) % 2)) &&
                          flag == 0
                      ? "YES"
                      : "NO")
              << "\n";
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
