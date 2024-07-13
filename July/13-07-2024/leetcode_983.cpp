#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int mincostTickets(vector<int>& days, vector<int>& costs) {
  int n = days.size();

  int dp[n][3];

  for (int i = 0; i < 3; i++) {
    dp[n - 1][i] = costs[i];
  }

  for (int i = n - 2; i >= 0; i--) {
    int idx;

    dp[i][0] = costs[0], dp[i][1] = costs[1], dp[i][2] = costs[2];

    if (days[i] + 1 <= *days.rbegin()) {
      idx = lower_bound(days.begin(), days.end(), days[i] + 1) - days.begin();
      dp[i][0] += min(dp[idx][0], min(dp[idx][1], dp[idx][2]));
    }

    if (days[i] + 7 <= *days.rbegin()) {
      idx = lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin();
      dp[i][1] += min(dp[idx][0], min(dp[idx][1], dp[idx][2]));
    }

    if (days[i] + 30 <= *days.rbegin()) {
      idx = lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin();
      dp[i][2] += min(dp[idx][0], min(dp[idx][1], dp[idx][2]));
    }
  }

  return min(dp[0][0], min(dp[0][1], dp[0][2]));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> d1 = {1, 4, 6, 7, 8, 20}, c1 = {2, 7, 15};
  vector<int> d2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, c2 = {2, 7, 15};

  cout << mincostTickets(d1, c1) << endl;
  cout << mincostTickets(d2, c2) << endl;

  return 0;
}
