#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MAX = 1e6 + 1;

vector<ll> primes;

void fill_primes() {
  vector<bool> isPrime(MAX, 1);

  for (ll i = 2; i <= MAX; i++) {
    if (isPrime[i]) {
      for (ll j = i * i; j <= MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }

  for (ll i = 2; i <= MAX; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }
}

ll find_min_val(vector<ll> a) {
  ll ans = a[0];
  for (ll i = 1; i < a.size(); i++) {
    ans = min(ans, a[i]);
  }
  return ans;
}

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<ll> ro(n, 0), co(m, 0);

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      ll x;
      cin >> x;
      auto itr = lower_bound(primes.begin(), primes.end(), x);
      ro[i] += (*itr) - x;
      co[j] += (*itr) - x;
    }
  }

  cout << min(find_min_val(ro), find_min_val(co)) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fill_primes();
  solve();
  return 0;
}
