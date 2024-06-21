#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void printYesOrNo(bool flag) {
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int number_of_winnings(int n, int k, vector<int> a) {
  int ans = 0, idx = -1;
  if (k > 0) ans++;
  for (int i = k + 1; i < n; i++) {
    if (a[i] > a[k]) {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    ans += n - 1 - k;
  } else {
    ans += idx - k - 1;
  }
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  k--;

  vector<int> a(n), b;
  for (int i = 0; i < n; i++) cin >> a[i];
  b = a;

  int a1, a2;
  swap(a[0], a[k]);

  a1 = number_of_winnings(n, 0, a);

  int idx = -1;
  for (int i = 0; i < k; i++) {
    if (b[i] > b[k]) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    swap(b[0], b[k]);
    a2 = number_of_winnings(n, 0, b);
  } else {
    swap(b[idx], b[k]);
    a2 = number_of_winnings(n, idx, b);
  }

  cout << max(a1, a2) << endl;
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
