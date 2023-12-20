#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll merge(vector<int> &a, vector<int> &t, int l, int mid, int r) {
  int i, j, k;
  ll cnt = 0;
  i = l, j = mid, k = l;
  while (i < mid && j <= r) {
    if (a[i] <= a[j]) {
      t[k++] = a[i++];
    } else {
      t[k++] = a[j++];
      cnt += (mid - i);
    }
  }
  while (i < mid) {
    t[k++] = a[i++];
  }
  while (j <= r) {
    t[k++] = a[j++];
  }
  for (i = l; i <= r; i++) {
    a[i] = t[i];
  }
  return cnt;
}

ll mergeSort(vector<int> &a, vector<int> &t, int l, int r) {
  int mid;
  ll cnt = 0;
  if (r > l) {
    mid = (r + l) / 2;
    cnt = mergeSort(a, t, l, mid);
    cnt += mergeSort(a, t, mid + 1, r);
    cnt += merge(a, t, l, mid + 1, r);
  }
  return cnt;
}

ll inversion(vector<int> &a, int n) {
  vector<int> t(n);
  return mergeSort(a, t, 0, n - 1);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = inversion(a, n);
  ll cur = 1;
  sort(a.begin(), a.end());
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) {
      ans += (cur * (cur - 1)) / 2;
      cur = 1;
    } else {
      cur++;
    }
  }
  ans += (cur * (cur - 1)) / 2;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
