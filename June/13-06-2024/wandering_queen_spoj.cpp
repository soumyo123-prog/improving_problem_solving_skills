#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

string grid[1001];
int dis[1001][1001];
int done[1001][1001];
int n, m, sx, sy, ex, ey;

bool is_valid(int r, int c) {
  if (r < 0 || c < 0) return false;
  if (r >= n || c >= m) return false;
  if (grid[r][c] == 'X') return false;
  return true;
}

int solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> grid[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dis[i][j] = (1 << 30);
      done[i][j] = 0;
      if (grid[i][j] == 'S') {
        sx = i;
        sy = j;
      } else if (grid[i][j] == 'F') {
        ex = i;
        ey = j;
      }
    }
  }

  dis[sx][sy] = 0;
  done[sx][sy] = 255;

  queue<pair<int, int>> q;
  q.push({sx, sy});

  while (!q.empty()) {
    pair<int, int> pos = q.front();
    q.pop();

    if (pos.first == ex && pos.second == ey) {
      return dis[ex][ey];
    }

    for (int i = 0; i < 8; i++) {
      int r = pos.first + dr[i], c = pos.second + dc[i];
      while (is_valid(r, c) && !(done[r][c] & (1 << i))) {
        if (!done[r][c]) {
          dis[r][c] = dis[pos.first][pos.second] + 1;
          q.push({r, c});
        }
        done[r][c] |= (1 << i);
        r += dr[i], c += dc[i];
      }
    }
  }

  return -1;
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
