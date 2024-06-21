#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll solve(ll n, ll a, ll b) {
  ll curr = 0;
  set<ll> st;
  map<ll, ll> mp;

  for (ll i = 1; i <= 2 * 1e6; i++) {
    mp[curr] = i;
    st.insert(curr);
    ll a1 = a % n, a2 = (curr * curr) % n;
    ll A = (a1 * a2) % n, B = b % n;
    curr = (A + B) % n;
    if (st.find(curr) != st.end()) {
      return n - i + mp[curr] - 1;
    }
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
