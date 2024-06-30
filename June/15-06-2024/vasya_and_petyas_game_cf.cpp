#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n;
  cin >> n;

  vector<bool> isPrime(n + 1, true);
  for (ll i = 2; i <= n; i++) {
    if (isPrime[i]) {
      for (ll j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  vector<ll> nums;
  for (ll i = 2; i <= n; i++) {
    if (isPrime[i]) {
      ll tmp = i;
      while (tmp <= n) {
        nums.push_back(tmp);
        tmp *= i;
      }
    }
  }

  cout << nums.size() << endl;
  for (auto i : nums) cout << i << ' ';
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
