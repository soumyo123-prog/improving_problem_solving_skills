#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void nextPermutation(vector<int>& nums) {
  int iLow = -1, iHigh = -1;

  for (int i = nums.size() - 1; i > 0; i--) {
    if (nums[i] > nums[i - 1]) {
      iLow = i - 1;
      break;
    }
  }

  if (iLow == -1) {
    goto reversing;
  }

  for (int i = nums.size() - 1; i > iLow; i--) {
    if (nums[i] > nums[iLow]) {
      iHigh = i;
      break;
    }
  }

  swap(nums[iLow], nums[iHigh]);

reversing:
  reverse(nums.begin() + iLow + 1, nums.end());
  for (auto i : nums) cout << i << ' ';
  cout << endl;
}

void solve() {
  vector<int> a = {3, 2, 1};
  nextPermutation(a);
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
