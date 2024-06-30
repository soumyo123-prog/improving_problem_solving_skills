#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int find_xor_util(int n) {
  int mod = n % 4;
  if (mod == 0) {
    return n;
  }
  if (mod == 1) {
    return 1;
  }
  if (mod == 2) {
    return n + 1;
  }
  return 0;
}

int find_xors(int n) {
  vector<int> xorArr;
  xorArr.push_back(0);

  for (int i = 2; i <= n; i++) {
    int quo = n / i, rem = n % i;
    if (quo % 2 == 0) {
      xorArr.push_back(find_xor_util(rem));
    } else {
      xorArr.push_back(find_xor_util(rem) ^ find_xor_util(i - 1));
    }
  }

  int fin = 0;
  for (int i = 0; i < n; i++) {
    fin = fin ^ xorArr[i];
  }
  return fin;
}

void solve() {
  int n;
  cin >> n;

  int x = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    x = x ^ num;
  }

  x = x ^ find_xors(n);
  cout << x << endl;
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
