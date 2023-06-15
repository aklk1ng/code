#include <bits/stdc++.h>

using namespace std;

class Soluton1 {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> st;
    vector<int> res(nums1.size(), -1);
    if (nums1.size() == 0)
      return res;

    unordered_map<int, int> umap;
    for (int i = 0; i < nums1.size(); i++)
      umap[nums1[i]] = i;

    st.push(0);

    for (int i = 1; i < nums2.size(); i++) {
      if (nums2[i] <= nums2[st.top()])
        st.push(i);
      else {
        while (!st.empty() && nums2[i] > nums2[st.top()]) {
          if (umap.count(nums2[st.top()]) > 0) {
            int index = nums2[st.top()];
            res[index] = nums2[i];
          }
          st.pop();
        }
        st.push(i);
      }
    }
    return res;
  }
};

class Soluton2 {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> st;
    vector<int> res(nums1.size(), -1);
    if (nums1.size() == 0)
      return res;

    unordered_map<int, int> umap;
    for (int i = 0; i < nums1.size(); i++)
      umap[nums1[i]] = i;

    st.push(0);

    for (int i = 1; i < nums2.size(); i++) {
      while (!st.empty() && nums2[i] > nums2[st.top()]) {
        if (umap.count(nums2[st.top()]) > 0) {
          int index = nums2[st.top()];
          res[index] = nums2[i];
        }
        st.pop();
      }
      st.push(i);
    }
    return res;
  }
};
