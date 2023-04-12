#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
    unordered_map<int, int> umap;
    for (auto a : nums1) {
      for (auto b : nums2) {
        umap[a + b]++;
      }
    }

    int count = 0;
    for (auto c : nums3) {
      for (auto d : nums4) {
        // umap.count(K key) method return
        // 1 => the specified key element is present in the unordered_map
        // 0 => the specified key element is not present in the unordered_map
        if (umap.count(0 - (c + d))) {
          count += umap[0 - (c + d)];
        }
      }
    }
    return count;
  }
};
