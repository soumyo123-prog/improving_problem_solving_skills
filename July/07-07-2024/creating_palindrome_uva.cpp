#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e4;
int a[MAX + 1];
map<pair<int, int>, int> dp;
int ans = INT_MAX;

void print_result(int testCase, int k, int d) {
  if (d == 0) {
    cout << "Case " << testCase << ": " << "Too easy" << endl;
  } else if (d <= k) {
    cout << "Case " << testCase << ": " << d << endl;
  } else {
    cout << "Case " << testCase << ": " << "Too difficult" << endl;
  }
}

void find_minimum_insertions(int l, int r, int sum) {
  if (l > r || sum >= ans) {
    if (sum < ans) ans = sum;
    return;
  }
  int &x = dp[make_pair(l, r)];
  if (x == 0 || sum < x) {
    x = sum;
    if (a[l] == a[r])
      find_minimum_insertions(l + 1, r - 1, sum);
    else {
      find_minimum_insertions(l, r - 1, sum + 1);
      find_minimum_insertions(l + 1, r, sum + 1);
    }
  }
}

void solve(int testCase) {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  dp.clear();
  ans = INT_MAX;
  find_minimum_insertions(0, n - 1, 0);
  print_result(testCase, k, ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
