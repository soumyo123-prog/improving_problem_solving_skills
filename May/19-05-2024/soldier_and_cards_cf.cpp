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
  int k1;
  cin >> k1;
  vector<int> p1(k1);
  for (int i = 0; i < k1; i++) {
    cin >> p1[i];
  }
  int k2;
  cin >> k2;
  vector<int> p2(k2);
  for (int i = 0; i < k2; i++) {
    cin >> p2[i];
  }

  deque<int> q1, q2;
  for (int i = 0; i < k1; i++) {
    q1.push_front(p1[i]);
  }
  for (int i = 0; i < k2; i++) {
    q2.push_front(p2[i]);
  }

  int numOfGames = 0;
  set<string> st;

  while (1) {
    if (q1.empty()) {
      cout << numOfGames << ' ' << 2 << endl;
      break;
    }
    if (q2.empty()) {
      cout << numOfGames << ' ' << 1 << endl;
      break;
    }

    string s = "";
    for (int i : q1) {
      s += to_string(i);
      s += " ";
    }
    for (int i : q2) {
      s += to_string(i);
      s += " ";
    }
    if (st.find(s) != st.end()) {
      cout << -1 << endl;
      break;
    }
    st.insert(s);
    numOfGames++;

    int i1 = q1.back(), i2 = q2.back();
    q1.pop_back();
    q2.pop_back();
    if (i1 > i2) {
      q1.push_front(i2);
      q1.push_front(i1);
    } else {
      q2.push_front(i1);
      q2.push_front(i2);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
