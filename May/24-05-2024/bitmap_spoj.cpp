#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 1e9;

int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

bool is_valid(int xi, int yi, int n, int m) {
  return xi < n && yi < m && xi >= 0 && yi >= 0;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<vector<int>> dist(n, vector<int>(m, inf));
  vector<vector<bool>> vis(n, vector<bool>(m, false));

  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '1') {
        dist[i][j] = 0;
        q.push({i, j});
        vis[i][j] = true;
      }
    }
  }

  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int xi = u.first + x[i], yi = u.second + y[i];
      if (is_valid(xi, yi, n, m) && !vis[xi][yi]) {
        vis[xi][yi] = true;
        q.push({xi, yi});
        dist[xi][yi] = min(dist[xi][yi], dist[u.first][u.second] + 1);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dist[i][j] << ' ';
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
