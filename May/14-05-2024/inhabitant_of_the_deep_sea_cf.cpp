#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  ll i1 = 0, i2 = a.size() - 1;
  bool tog = 0;
  while (i2 > i1) {
    ll ra;

    if (a[i1] < a[i2]) {
      if (!tog) {
        ra = 2 * a[i1] - 1;
      } else {
        ra = 2 * a[i1];
      }
      if (k >= ra) {
        if (!tog) {
          a[i2] -= (a[i1] - 1);
        } else {
          a[i2] -= a[i1];
        }
        a[i1] = 0;
        k -= ra;
        i1++;
        if (ra % 2 != 0) tog = !tog;
      } else {
        break;
      }
    } else if (a[i1] > a[i2]) {
      if (!tog) {
        ra = 2 * a[i2];
      } else {
        ra = 2 * a[i2] - 1;
      }
      if (k >= ra) {
        if (!tog) {
          a[i1] -= a[i2];
        } else {
          a[i1] -= (a[i2] - 1);
        }
        a[i2] = 0;
        k -= ra;
        i2--;
        if (ra % 2 != 0) tog = !tog;
      } else {
        break;
      }
    } else {
      ra = 2 * a[i1] - 1;
      if (k >= ra) {
        if (!tog) {
          a[i1] = 0;
          a[i2] = 1;
          i1++;
        } else {
          a[i1] = 1;
          a[i2] = 0;
          i2--;
        }
        k -= ra;
        tog = !tog;
      } else {
        break;
      }
    }
  }
  if (i2 == i1 && k >= a[i1]) {
    a[i1] = 0;
  }

  cout << count(a.begin(), a.end(), 0) << endl;
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
