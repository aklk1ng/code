#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  char slowestKey(vector<int> &releaseTimes, string keysPressed) {
    char res = keysPressed[0];
    int maxtime = releaseTimes[0];
    for (int i = 1; i < keysPressed.size(); i++) {
      int time = releaseTimes[i] - releaseTimes[i - 1];
      if (time > maxtime || (time == maxtime && keysPressed[i] > res)) {
        res = keysPressed[i];
        maxtime = time;
      }
    }
    return res;
  }
};
