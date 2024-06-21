#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void printYesOrNo(bool flag) {
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  vector<pair<int, int>> v1, v2;
  for (int i = 1; i < n - 1; i += 2) {
    v1.push_back({p[i], i});
  }
  for (int i = 2; i < n - 1; i += 2) {
    v2.push_back({p[i], i});
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  vector<int> r = p;
  sort(r.begin(), r.end());

  int i1 = 0, i2 = n - 1;
  vector<int> a1(n, 0), a2(n, 0);
  for (int i = 0; i < v1.size(); i++) {
    a1[v1[i].second] = v1[i].first + r[i2--];
    if (i == 0) {
      a1[v1[i].second - 1] = p[v1[i].second - 1] + r[i1++];
    }
    a1[v1[i].second + 1] = p[v1[i].second + 1] + r[i1++];
  }
  for (int i = 0; i < n; i++) {
    if (a1[i] == 0) {
      a1[i] = p[i] + r[i1++];
    }
  }

  i1 = 0, i2 = n - 1;
  for (int i = 0; i < v2.size(); i++) {
    a2[v2[i].second] = v2[i].first + r[i2--];
    if (i == 0) {
      a2[v2[i].second - 1] = p[v2[i].second - 1] + r[i1++];
    }
    a2[v2[i].second + 1] = p[v2[i].second + 1] + r[i1++];
  }
  for (int i = 0; i < n; i++) {
    if (a2[i] == 0) {
      a2[i] = p[i] + r[i1++];
    }
  }

  int nm1 = 0, nm2 = 0;
  for (int i = 1; i < n - 1; i++) {
    if (a1[i] > a1[i - 1] && a1[i] > a1[i + 1]) {
      nm1++;
    }
    if (a2[i] > a2[i - 1] && a2[i] > a2[i + 1]) {
      nm2++;
    }
  }

  if (nm1 > nm2) {
    for (int i = 0; i < n; i++) {
      cout << a1[i] - p[i] << ' ';
      // cout << a1[i] << ' ';
    }
    cout << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << a2[i] - p[i] << ' ';
      // cout << a2[i] << ' ';
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
