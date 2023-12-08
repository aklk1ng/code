#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ifstream f("input.txt");
  string input;
  vector<ll> v;
  ll res = -1;
  ll sum = 0;
  while (getline(f, input)) {
    if (input.empty()) {
      v.push_back(sum);
      sum = 0;
      continue;
    }
    sum += stoi(input);
  }
  sort(v.rbegin(), v.rend());
  cout << v[0] + v[1] + v[2] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
