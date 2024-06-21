#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;

    int n = x.length(), i = 0;
    while (i < n) {
      if (x[i] == y[i]) {
        i++;
      } else {
        if (x[i] < y[i]) {
          char z = x[i];
          x[i] = y[i];
          y[i] = z;
        }
        i++;
        break;
      }
    }

    while (i < n) {
      if (x[i] > y[i]) {
        char z = x[i];
        x[i] = y[i];
        y[i] = z;
      }
      i++;
    }

    cout << x << endl;
    cout << y << endl;
  }

  return 0;
}