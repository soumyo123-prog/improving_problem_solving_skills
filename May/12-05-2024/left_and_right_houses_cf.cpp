#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int divide_by_2(int x) {
  if (x % 2 == 0) return x / 2;
  return (x / 2 + 1);
}

int solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> lc(n, 0), rc(n, 0);
  if (s[0] == '0') {
    lc[0] = 1;
  } else {
    rc[0] = 1;
  }

  for (int i = 1; i < n; i++) {
    lc[i] = lc[i - 1];
    rc[i] = rc[i - 1];
    if (s[i] == '0') {
      lc[i]++;
    } else {
      rc[i]++;
    }
  }

  int left = 0, right = rc[n - 1];
  vector<int> answers;

  if (right >= divide_by_2(n)) {
    answers.push_back(0);
  }

  for (int i = 0; i < n; i++) {
    left = lc[i];
    right = rc[n - 1] - rc[i];
    if (left >= divide_by_2(i + 1) && right >= divide_by_2(n - i - 1)) {
      answers.push_back(i + 1);
    }
  }

  int ans = answers[0], cmp = n - 2 * answers[0];
  for (int i = 1; i < answers.size(); i++) {
    if (abs(n - 2 * answers[i]) < cmp) {
      cmp = abs(n - 2 * answers[i]);
      ans = answers[i];
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
