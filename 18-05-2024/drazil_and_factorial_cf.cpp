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

  vector<int> a;
  for (int i = 0; i < n; i++) {
    switch (s[i]) {
      case '0':
        break;
      case '1':
        break;
      case '4':
        a.push_back(2);
        a.push_back(2);
        a.push_back(3);
        break;
      case '6':
        a.push_back(3);
        a.push_back(5);
        break;
      case '8':
        a.push_back(2);
        a.push_back(2);
        a.push_back(2);
        a.push_back(7);
        break;
      case '9':
        a.push_back(3);
        a.push_back(3);
        a.push_back(2);
        a.push_back(7);
        break;
      default:
        a.push_back(s[i] - '0');
        break;
    }
  }

  sort(a.begin(), a.end(), greater<int>());
  for (auto i : a) cout << i;
  cout << endl;
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
