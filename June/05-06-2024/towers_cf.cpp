#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  int n, k;
  cin >> n >> k;

  multiset<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.insert({x, i});
  }

  int diff = a.rbegin()->first - a.begin()->first;
  vector<pair<int, int>> operations;
  while (k > 0 && diff >= 2) {
    pair<int, int> p1 = *a.begin(), p2 = *a.rbegin();
    a.erase(a.find(p1));
    a.erase(a.find(p2));
    p1.first++;
    p2.first--;
    a.insert(p1);
    a.insert(p2);
    operations.push_back({p2.second + 1, p1.second + 1});
    int i1 = a.begin()->first, i2 = a.rbegin()->first;
    diff = i2 - i1;
    k--;
  }

  cout << diff << ' ' << operations.size() << endl;
  for (int i = 0; i < operations.size(); i++) {
    cout << operations[i].first << ' ' << operations[i].second << endl;
  }
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
