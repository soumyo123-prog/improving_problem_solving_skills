#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> binaryDecimals(33);

void printYesOrNo(bool flag) {
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int find_binary_decimal(int n) {
  int result = 0;
  int base = 1;
  while (n > 0) {
    int digit = n % 2;
    result += digit * base;
    n /= 2;
    base *= 10;
  }
  return result;
}

string findFor(int n) {
  string yes = "YES", no = "NO";

  for (int i = 2; i <= 32; i++) {
    if (binaryDecimals[i] == n) {
      return yes;
    }
  }

  int idx = -1;
  for (int i = 2; i <= 32; i++) {
    if (n % binaryDecimals[i] == 0) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    return no;
  }

  int newNum = n / binaryDecimals[idx];
  return findFor(newNum);
}

string solve() {
  int n;
  cin >> n;
  if (n == 1) {
    return "YES";
  }
  return findFor(n);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 1; i <= 32; i++) {
    binaryDecimals[i] = find_binary_decimal(i);
  }

  int t = 1;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
