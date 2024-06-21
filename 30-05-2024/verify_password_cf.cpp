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
  string s;
  cin >> s;

  string nums = "", letters = "";
  for (int i = 0; i < n; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      letters += s[i];
    } else {
      nums += s[i];
    }
  }
  sort(nums.begin(), nums.end());
  sort(letters.begin(), letters.end());

  printYesOrNo(s == nums + letters);
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
