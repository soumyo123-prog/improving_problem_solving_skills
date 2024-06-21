#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool isNotPrime[10000001];
vector<ll> primes;

void fillPrimeNumbers() {
  for (ll i = 2; i < 10000001; i++) {
    if (!isNotPrime[i]) {
      for (ll j = i * i; j < 10000001; j += i) {
        isNotPrime[j] = true;
      }
    }
  }
  for (ll i = 2; i < 10000001; i++) {
    if (!isNotPrime[i]) primes.push_back(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fillPrimeNumbers();

  ll n;
  while (cin >> n) {
    if (n < 8) {
      cout << "Impossible." << endl;
      continue;
    }

    vector<ll> res(4);
    if (n % 2 == 0) {
      res[0] = 2;
      res[1] = 2;
      n -= 4;
    } else {
      res[0] = 2;
      res[1] = 3;
      n -= 5;
    }

    int i = 0;
    while (primes[i] < n) {
      if (!isNotPrime[n - primes[i]]) {
        res[2] = primes[i];
        res[3] = n - primes[i];
        break;
      }
      i++;
    }

    cout << res[0] << ' ' << res[1] << ' ' << res[2] << ' ' << res[3] << endl;
  }

  return 0;
}
