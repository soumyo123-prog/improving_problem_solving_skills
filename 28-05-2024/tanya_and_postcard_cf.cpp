#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  string s, t;
  cin >> s >> t;

  vector<pair<int, int>> cnt(256, {0, 0});
  for (int i = 0; i < s.size(); i++) {
    cnt[s[i]].first++;
  }
  for (int i = 0; i < t.size(); i++) {
    cnt[t[i]].second++;
  }

  int yay = 0, whoops = 0;

  for (int i = 0; i < 256; i++) {
    bool cond = (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z');
    if (!cond) continue;

    int c1 = cnt[i].first, c2 = cnt[i].second;
    cnt[i].first -= min(c1, c2);
    cnt[i].second -= min(c1, c2);
    yay += min(c1, c2);
  }

  for (int i = 0; i < 256; i++) {
    bool cond = (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z');
    if (!cond) continue;

    if (cnt[i].first > 0) {
      int c1, c2;
      c1 = cnt[i].first;
      c2 = cnt[i + (i < 'a' ? 'a' - 'A' : 'A' - 'a')].second;
      cnt[i].first -= min(c1, c2);
      cnt[i + (i < 'a' ? 'a' - 'A' : 'A' - 'a')].second -= min(c1, c2);
      whoops += min(c1, c2);
    }
  }

  cout << yay << ' ' << whoops << endl;
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
