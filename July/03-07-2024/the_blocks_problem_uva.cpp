#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const string move = "move";
const string pile = "pile";
const string onto = "onto";
const string over = "over";
const string quit = "quit";

vector<string> split(string &s, char delimiter) {
  vector<string> result;
  string curr = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == delimiter) {
      if (curr.size() > 0) result.push_back(curr);
      curr = "";
    } else {
      curr += s[i];
    }
  }
  if (curr.size() > 0) {
    result.push_back(curr);
  }
  return result;
}

void move_onto(int n1, int n2, pair<int, int> p1, pair<int, int> p2,
               vector<vector<int>> &a, vector<pair<int, int>> &pos) {
  while (*(a[p1.first].rbegin()) != n1) {
    int num = *(a[p1.first].rbegin());
    a[p1.first].pop_back();
    a[num].push_back(num);
    pos[num].first = num;
    pos[num].second = a[num].size() - 1;
  }
  while (*(a[p2.first].rbegin()) != n2) {
    int num = *(a[p2.first].rbegin());
    a[p2.first].pop_back();
    a[num].push_back(num);
    pos[num].first = num;
    pos[num].second = a[num].size() - 1;
  }
  a[n2].push_back(n1);
  pos[n1].first = n2;
  pos[n2].second = a[n2].size() - 1;
}

void move_over(int n1, int n2, pair<int, int> p1, pair<int, int> p2,
               vector<vector<int>> &a, vector<pair<int, int>> &pos) {
  queue<int> q;

  int num = *(a[p1.first].rbegin());
  while (num != n1) {
    q.push(num);
    a[p1.first].pop_back();
    num = *(a[p1.first].rbegin());
  }
  q.push(num);
  a[p1.first].pop_back();

  while (!q.empty()) {
    }
}

void pile_onto(int n1, int n2, pair<int, int> p1, pair<int, int> p2,
               vector<vector<int>> &a, vector<pair<int, int>> &pos) {}

void pile_over(int n1, int n2, pair<int, int> p1, pair<int, int> p2,
               vector<vector<int>> &a, vector<pair<int, int>> &pos) {}

void solve() {
  int n;
  cin >> n;
  cin.ignore();

  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = {i};
  }

  vector<pair<int, int>> pos(n);
  for (int i = 0; i < n; i++) {
    pos[i] = {i, 0};
  }

  string s;
  while (getline(cin, s)) {
    if (s == quit) {
      break;
    }
    vector<string> words = split(s, ' ');
    int n1 = words[1][0] - '0', n2 = words[3][0] - '0';
    pair<int, int> p1 = pos[n1], p2 = pos[n2];

    if (words[0] == move) {
      if (words[2] == onto) {
        move_onto(n1, n2, p1, p2, a, pos);
      } else {
        move_over(n1, n2, p1, p2, a, pos);
      }
    } else {
      if (words[2] == onto) {
        pile_onto(n1, n2, p1, p2, a, pos);
      } else {
        pile_over(n1, n2, p1, p2, a, pos);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << ": ";
    for (int j = 0; j < a[i].size(); j++) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
