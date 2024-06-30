#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> res = {0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3, 1};

int helper(int n1, int n3, int n6, int n10, int num) {
  if (num <= 15) {
    return res[num];
  }

  int a1 = INT_MAX, a2 = INT_MAX, a3 = INT_MAX, a4 = INT_MAX;
  if (n1 < 2 && num - 1 > 0) {
    a1 = 1 + helper(n1 + 1, n3, n6, n10, num - 1);
  }
  if (n3 < 1 && num - 3 > 0) {
    a2 = 1 + helper(n1, n3 + 1, n6, n10, num - 3);
  }
  if (n6 < 4 && num - 6 > 0) {
    a3 = 1 + helper(n1, n3, n6 + 1, n10, num - 6);
  }
  if (n10 < 2 && num - 10 > 0) {
    a4 = 1 + helper(n1, n3, n6, n10 + 1, num - 10);
  }

  return min(num / 15 + res[num % 15], min(a1, min(a2, min(a3, a4))));
}

void solve() {
  int n;
  cin >> n;

  cout << helper(0, 0, 0, 0, n) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
