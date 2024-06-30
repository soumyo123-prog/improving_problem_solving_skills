#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

vector<ll> convertIntoArray(string line) {
  string tmp = "";
  vector<ll> separatedIntegers;
  for (ll i = 0; i < line.size(); i++) {
    if (line[i] == ' ') {
      if (tmp.size() > 0) separatedIntegers.push_back(stoi(tmp));
      tmp = "";
    } else {
      tmp += line[i];
    }
  }
  if (tmp.size() > 0) separatedIntegers.push_back(stoi(tmp));
  return separatedIntegers;
}

void solve(string firstLine, string secondLine) {
  vector<ll> coefficients = convertIntoArray(firstLine);
  vector<ll> values = convertIntoArray(secondLine);
  reverse(coefficients.begin(), coefficients.end());

  for (ll i = 0; i < values.size(); i++) {
    ll x = values[i];
    ll sum = 0;
    for (ll j = 0; j < coefficients.size(); j++) {
      sum += coefficients[j] * binpow(x, j);
    }
    cout << sum << ' ';
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string inputLine, firstLine, secondLine;
  ll lineNumber = 0;
  while (getline(cin, inputLine)) {
    lineNumber++;
    if (lineNumber % 2 == 0) {
      secondLine = inputLine;
      solve(firstLine, secondLine);
    } else {
      firstLine = inputLine;
    }
  }
  return 0;
}
