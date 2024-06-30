#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  string m;
  cin >> m;

  // sort(a.begin(), a.end(), greater<pair<ll, ll>>());

  ll nm = 0;
  for (ll i = 1; i <= n; i++) {
    nm += i * (m[i - 1] - '0');
  }

  ll nx = 0, currSum = 0, maxSum = 0;

  ll i = 0, start = 0;
  while (i < n) {
    nx += a[i].second;
    currSum += a[i].first;
    if (nx <= nm) {
      maxSum = max(maxSum, currSum);
    } else {
      while (nx > nm) {
        nx -= a[start].second;
        currSum -= a[start].first;
        start++;
      }
      maxSum = max(maxSum, currSum);
    }
    i++;
  }
  maxSum = max(maxSum, currSum);

  cout << maxSum << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}