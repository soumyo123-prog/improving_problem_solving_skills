#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool identical_array(int n, vector<int> a) {
  int a0 = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] != a0) return false;
  }
  return true;
}

int solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  if (identical_array(n, a)) return -1;

  if (a[0] == a[n - 1]) {
    vector<int> nums;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == a[0]) {
        cnt++;
      } else {
        nums.push_back(cnt);
        cnt = 0;
      }
    }
    nums.push_back(cnt);

    int ans = INT_MAX;
    for (auto i : nums) ans = min(ans, i);
    return ans;
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
