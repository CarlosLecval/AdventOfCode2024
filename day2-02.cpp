#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isValid(vector<int> &a) {
  bool isIncreasing;
  int prevNumber;
  int difference = a[0] - a[1];

  if (difference > 3 || difference < -3 || difference == 0)
    return false;
  isIncreasing = difference > 0;

  for (int i = 2; i < a.size(); i++) {
    difference = a[i - 1] - a[i];
    if (difference > 3 || difference < -3 || difference == 0 ||
        isIncreasing != (difference > 0)) {
      return false;
    }
  }
  return true;
}

bool checkRemovingElement(vector<int> &a, int ind) {
  vector<int> b = a;
  b.erase(b.begin() + ind);
  return isValid(b);
}

int main() {
  freopen("input.txt", "r", stdin);
  int count = 0;
  int number;
  int difference;
  string s;
  while (getline(cin, s)) {
    bool isSafe = false;
    vector<int> a;
    istringstream stream(s);
    while (stream >> number)
      a.push_back(number);
    isSafe = isValid(a);
    if (isSafe) {
      count++;
      continue;
    }
    for (int i = 0; i < a.size() - 1; i++) {
      difference = a[i + 1] - a[i];
      if (abs(difference) < 1 || abs(difference) > 3) {
        isSafe = isSafe || checkRemovingElement(a, i);
        isSafe = isSafe || checkRemovingElement(a, i + 1);
        break;
      }
      if (i + 2 < a.size()) {
        int diff2 = a[i + 2] - a[i + 1];
        bool areBothIncreasing = (difference > 0) == (diff2 > 0);
        if (areBothIncreasing)
          continue;
        isSafe = isSafe || checkRemovingElement(a, i);
        isSafe = isSafe || checkRemovingElement(a, i + 1);
        isSafe = isSafe || checkRemovingElement(a, i + 2);
        break;
      }
    }
    if (isSafe) {
      count++;
    }
  }
  cout << count << endl;
}
