#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> m;
    for (auto num : nums1)
      m[num]++;

    vector<int> res;
    for (auto num : nums2) {
      if (m.count(num)) {
        res.push_back(num);
        m[num]--;
      }
      if (m[num] == 0)
        m.erase(num);
    }
    return res;
  }
};

class Solution2 {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    int ptr1 = 0, ptr2 = 0;
    vector<int> res;
    while (ptr1 < len1 && ptr2 < len2) {
      if (nums1[ptr1] < nums2[ptr2])
        ptr1++;
      else if (nums1[ptr1] > nums2[ptr2])
        ptr2++;
      else {
        res.push_back(nums1[ptr1]);
        ptr1++;
        ptr2++;
      }
    }
    return res;
  }
};
