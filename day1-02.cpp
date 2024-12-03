#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int x, y;
  int sum = 0;
  vector<int> left;
  unordered_map<int, int> right;

  while (cin >> x >> y) {
    left.push_back(x);
    right[y]++;
  }
  for (int i = 0; i < left.size(); i++) {
    sum += left[i] * right[left[i]];
  }
  cout << sum << endl;
}
