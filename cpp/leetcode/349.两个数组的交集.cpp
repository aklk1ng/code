#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> res;
    unordered_set<int> nums_set(nums1.begin(), nums1.end());
    for (auto &num : nums2) {
      if (nums_set.find(num) != nums_set.end()) {
        res.insert(num);
      }
    }
    return vector<int>(res.begin(), res.end());

    // int hash[1005] = {0};
    // for (auto num : nums1) {
    //   hash[num] = 1;
    // }
    // for (auto num : nums2) {
    //   if (hash[num] == 1) {
    //     res.insert(num);
    //   }
    // }
    // return vector<int>(res.begin(), res.end());
  }
};
