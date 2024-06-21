#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const string possible = "Possible";
const string impossible = "Impossible";

bool nextPermutation(vector<ll>& nums) {
  ll iLow = -1, iHigh = -1;

  for (ll i = nums.size() - 1; i > 0; i--) {
    if (nums[i] > nums[i - 1]) {
      iLow = i - 1;
      break;
    }
  }

  if (iLow == -1) {
    return false;
  }

  for (ll i = nums.size() - 1; i > iLow; i--) {
    if (nums[i] > nums[iLow]) {
      iHigh = i;
      break;
    }
  }

  swap(nums[iLow], nums[iHigh]);
  reverse(nums.begin() + iLow + 1, nums.end());
  return true;
}

ll evaluate(ll a, ll b, char oper) {
  if (oper == '+') return a + b;
  if (oper == '-') return a - b;
  return a * b;
}

string solve(vector<ll> a) {
  sort(a.begin(), a.end());

  vector<vector<ll>> perms;
  do {
    perms.push_back(a);
  } while (nextPermutation(a));

  vector<char> opers = {'+', '-', '*'};

  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < 3; j++) {
      for (ll k = 0; k < 3; k++) {
        for (ll l = 0; l < 3; l++) {
          for (ll m = 0; m < perms.size(); m++) {
            ll res = evaluate(perms[m][0], perms[m][1], opers[i]);
            res = evaluate(res, perms[m][2], opers[j]);
            res = evaluate(res, perms[m][3], opers[k]);
            res = evaluate(res, perms[m][4], opers[l]);
            if (res == 23) {
              return possible;
            }
          }
        }
      }
    }
  }

  return impossible;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<ll> a(5);
  while (cin >> a[0]) {
    if (a[0] == 0) {
      break;
    }
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    cout << solve(a) << endl;
  }
  return 0;
}
