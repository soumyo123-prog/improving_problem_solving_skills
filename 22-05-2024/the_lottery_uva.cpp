#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll find_lcm(vector<ll> a) {
  ll lcm = a[0];
  for (ll i = 1; i < a.size(); i++) {
    lcm = (lcm * a[i]) / __gcd(lcm, a[i]);
  }
  return lcm;
}

void solve(ll n, ll m) {
  vector<ll> nums(m);
  for (ll i = 0; i < m; i++) cin >> nums[i];

  ll oc = 0, ec = 0;

  for (ll i = 1; i < (1 << m); i++) {
    vector<ll> t;
    for (ll j = 0; j < m; j++) {
      if (i & (1 << j)) {
        t.push_back(nums[j]);
      }
    }

    ll multiples = n / find_lcm(t);
    if (t.size() % 2 == 0) {
      ec += multiples;
    } else {
      oc += multiples;
    }
  }

  cout << n - oc + ec << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, m;
  while (cin >> n && cin >> m) {
    solve(n, m);
  }
  return 0;
}
