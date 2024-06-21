#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int counter = 0;

bool nextPermutation(vector<int>& nums) {
  int iLow = -1, iHigh = -1;

  for (int i = nums.size() - 1; i > 0; i--) {
    if (nums[i] > nums[i - 1]) {
      iLow = i - 1;
      break;
    }
  }

  if (iLow == -1) {
    return false;
  }

  for (int i = nums.size() - 1; i > iLow; i--) {
    if (nums[i] > nums[iLow]) {
      iHigh = i;
      break;
    }
  }

  swap(nums[iLow], nums[iHigh]);
  reverse(nums.begin() + iLow + 1, nums.end());
  return true;
}

bool check(int r, int c, vector<int> perm) {
  bool rd[30] = {false}, ld[30] = {false};

  rd[perm[0] + 1] = true;
  ld[perm[0] - 1 + 7] = true;

  for (int i = 1; i < perm.size(); i++) {
    if (rd[perm[i] + (i + 1)] || ld[perm[i] - i - 1 + 7]) {
      return false;
    }
    rd[perm[i] + (i + 1)] = true;
    ld[perm[i] - i - 1 + 7] = true;
  }
  return true;
}

void solve() {
  int r, c;
  cin >> r >> c;

  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

  vector<vector<int>> perms;
  do {
    if (v[c - 1] == r) {
      perms.push_back(v);
    }
  } while (nextPermutation(v));

  vector<vector<int>> result;

  for (int i = 0; i < perms.size(); i++) {
    if (check(r, c, perms[i])) {
      result.push_back(perms[i]);
    }
  }

  cout << "SOLN       COLUMN" << endl;
  cout << " #      1 2 3 4 5 6 7 8" << endl;
  cout << endl;
  for (int i = 1; i <= result.size(); i++) {
    cout << " " << i << "      ";
    for (int j = 0; j < result[i - 1].size(); j++) {
      cout << result[i - 1][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
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
