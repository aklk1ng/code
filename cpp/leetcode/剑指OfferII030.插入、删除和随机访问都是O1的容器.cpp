#include <bits/stdc++.h>

using namespace std;

class RandomizeSet {
public:
  RandomizeSet() { srand((unsigned)time(NULL)); }

  bool insert(int val) {
    if (map.count(val))
      return false;

    int index = nums.size();
    nums.emplace_back(val);
    map[val] = index;

    return true;
  }

  bool remove(int val) {
    if (!map.count(val))
      return false;

    // get index and the last value
    int index = map[val];
    int last = nums.back();

    nums[index] = last;
    map[last] = index;

    nums.pop_back();
    map.erase(val);

    return true;
  }

  int getRandom() {
    int randomIndex = rand() % nums.size();
    return nums[randomIndex];
  }

private:
  vector<int> nums;
  unordered_map<int, int> map;
};
