#include <bits/stdc++.h>

using namespace std;

class FindSumPairs {
public:
  vector<int> nums1, nums2;
  unordered_map<int, int> cnt;

  FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;

    for (int num : nums2)
      cnt[num]++;
  }

  void add(int index, int val) {
    cnt[nums2[index]]--;
    nums2[index] += val;
    cnt[nums2[index]]++;
  }

  int count(int tot) {
    int res = 0;
    for (int num : nums1) {
      int rest = tot - num;
      if (cnt.count(rest))
        res += cnt[rest];
    }
    return res;
  }
};
