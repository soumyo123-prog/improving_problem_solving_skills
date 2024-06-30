#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<ll> cubes;

ll find_index(ll n) {
  ll s = 0, e = cubes.size() - 1;
  ll ans = 0;
  while (s <= e) {
    ll mid = s + (e - s) / 2;
    if (cubes[mid] <= n) {
      ans = mid;
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  return ans;
}

double find_cube_root(double n) {
  ll a = find_index(n) + 1;
  double dx = (n - a * a * a) / (3 * a * a);
  return a + dx;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll num = 1;
  while (num <= 1000) {
    cubes.push_back(num * num * num);
    num++;
  }

  double n;
  while (cin >> n) {
    if (n == 0) break;
    cout << fixed << setprecision(4) << find_cube_root(n) << endl;
  }

  return 0;
}
