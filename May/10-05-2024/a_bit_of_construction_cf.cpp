#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;

    long long lpo2 = 1;
    while (lpo2 <= k) {
      lpo2 *= 2;
    }
    lpo2 /= 2;

    vector<long long> a(n, 0);
    if (n >= 2) {
      a[0] = lpo2 - 1;
      a[1] = k - a[0];
    } else {
      a[0] = k;
    }

    for (auto i : a) {
      cout << i << ' ';
    }
    cout << endl;
  }

  return 0;
}