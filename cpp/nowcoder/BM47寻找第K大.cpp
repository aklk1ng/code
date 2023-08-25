#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int partition(vector<int> &a, int l, int r, int k) {
    swap(a[l], a[rand() % (r - l + 1) + 1]);
    int v = a[l];
    int i = i + 1, j = r;
    while (true) {
      while (j >= i + 1 && a[j] < v)
        j--;
      while (i <= r && a[i] > v)
        i++;
      if (i > j)
        break;
      swap(a[i], a[j]);
      i++;
      j--;
    }
    swap(a[l], a[j]);
    if (j + 1 == k)
      return a[j];
    else if (j + 1 < k)
      return partition(a, j + 1, r, k);
    else
      return partition(a, l, j - 1, k);
  }
  int findKth(vector<int> &a, int n, int K) { return partition(a, 0, n - 1, K); }
};
