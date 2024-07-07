#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string generate_line(ll n, ll m, bool redFirst) {
  ll len = n + m;

  vector<char> vs(len);
  if (redFirst) {
    vs[0] = 'R';
    n--;
  } else {
    vs[0] = 'B';
    m--;
  }

  for (ll i = 1; i < len; i++) {
    if (i % 2 == 0) {
      if (vs[i - 1] == 'R') {
        if (n > 0) {
          n--;
          vs[i] = 'R';
        } else {
          m--;
          vs[i] = 'B';
        }
      } else {
        if (m > 0) {
          m--;
          vs[i] = 'B';
        } else {
          n--;
          vs[i] = 'R';
        }
      }
    } else {
      if (vs[i - 1] == 'R') {
        if (m > 0) {
          m--;
          vs[i] = 'B';
        } else {
          n--;
          vs[i] = 'R';
        }
      } else {
        if (n > 0) {
          n--;
          vs[i] = 'R';
        } else {
          m--;
          vs[i] = 'B';
        }
      }
    }
  }

  string s = "";
  for (ll i = 0; i < len; i++) {
    s += vs[i];
  }
  return s;
}

pair<ll, ll> calculate_scores(string s) {
  pair<ll, ll> scores = {0, 0};
  for (ll i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      scores.first++;
    } else {
      scores.second++;
    }
  }
  return scores;
}

void solve() {
  ll n, m;
  cin >> n >> m;

  string redFirst = generate_line(n, m, true);
  string blueFirst = generate_line(n, m, false);

  pair<ll, ll> s1 = calculate_scores(redFirst),
               s2 = calculate_scores(blueFirst);
  if (s1.first > s2.first) {
    cout << s1.first << ' ' << s1.second << endl;
  } else {
    cout << s2.first << ' ' << s2.second << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
