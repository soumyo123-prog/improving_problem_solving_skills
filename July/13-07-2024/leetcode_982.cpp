#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool check_ith_set_bit(int num, int bit) {
  if (num & (1 << bit)) {
    return true;
  }
  return false;
}

int get_bit(int num, int bit) {
  if (num & (1 << bit)) {
    return 1;
  }
  return 0;
}

int countTriplets(vector<int>& nums) {
  int res = 0, n = nums.size();

  map<int, int> mp;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mp[nums[i] & nums[j]]++;
    }
  }

  for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++) {
    for (int j = 0; j < n; j++) {
      if ((i->first & nums[j]) == 0) {
        res += i->second;
      }
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> a = {2, 1, 3};
  vector<int> b = {0, 0, 0};

  cout << countTriplets(a) << endl;
  cout << countTriplets(b) << endl;

  return 0;
}
