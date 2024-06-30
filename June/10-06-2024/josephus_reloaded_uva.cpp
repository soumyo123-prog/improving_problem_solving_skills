#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll solve(ll n, ll a, ll b) {
  ll members = 1, curr = 0;

  for (ll i = 1; i <= 2 * 1e6; i++) {
    ll a1 = a % n, a2 = (curr * curr) % n;
    ll A = (a1 * a2) % n, B = b % n;
    curr = (A + B) % n;
    if (curr == 0) {
      return n - members;
      break;
    }
    members++;
  }

  return n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (1) {
    ll n, a, b;
    cin >> n >> a >> b;
    if (n == 0) break;
    cout << solve(n, a, b) << endl;
  }
  return 0;
}
