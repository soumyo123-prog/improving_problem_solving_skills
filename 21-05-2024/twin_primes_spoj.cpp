#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool isNotPrime[20000001];
vector<ll> twinPrimes;

void findTwinPrimes() {
  for (ll i = 2; i <= 20000000; i++) {
    if (!isNotPrime[i]) {
      for (ll j = i * i; j <= 20000000; j += i) {
        isNotPrime[j] = true;
      }
    }
  }

  ll primeNum = 2;
  for (ll i = 3; i <= 20000000; i++) {
    if (!isNotPrime[i]) {
      if (i - primeNum == 2) {
        twinPrimes.push_back(primeNum);
      }
      primeNum = i;
    }
  }
}

void solve() {
  ll n;
  cin >> n;

  cout << twinPrimes[n - 1] << ' ' << twinPrimes[n - 1] + 2 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  findTwinPrimes();

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
