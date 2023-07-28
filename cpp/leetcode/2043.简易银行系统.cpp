#include <bits/stdc++.h>

using namespace std;

class Bank {
public:
  bool isvalid(int account) { return account <= balance.size(); }
  Bank(vector<long long> &balance) : balance(balance) {}

  bool transfer(int account1, int account2, long long money) {
    if (isvalid(account1) && isvalid(account2) && balance[account1 - 1] >= money) {
      balance[account1 - 1] -= money;
      balance[account2 - 1] += money;
      return true;
    }
    return false;
  }

  bool deposit(int account, long long money) {
    if (isvalid(account)) {
      balance[account - 1] += money;
      return true;
    }
    return false;
  }

  bool withdraw(int account, long long money) {
    if (isvalid(account) && balance[account - 1] >= money) {
      balance[account - 1] -= money;
      return true;
    }
    return false;
  }

private:
  vector<long long> balance;
};
