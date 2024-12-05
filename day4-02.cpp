#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int searchWord(vector<string> &vec, int &row, int &col) {
  int count = 0;
  if (row == 0 || col == 0 || row == vec.size() - 1 || col == vec[0].size() - 1)
    return 0;
  if (vec[row - 1][col - 1] == 'S' && vec[row + 1][col + 1] == 'M') {
    count++;
  } else if (vec[row - 1][col - 1] == 'M' && vec[row + 1][col + 1] == 'S') {
    count++;
  }
  if (vec[row - 1][col + 1] == 'S' && vec[row + 1][col - 1] == 'M') {
    count++;
  } else if (vec[row - 1][col + 1] == 'M' && vec[row + 1][col - 1] == 'S') {
    count++;
  }
  if (count != 2)
    return 0;
  return 1;
}

int main() {
  freopen("input.txt", "r", stdin);
  vector<string> vec;
  int res = 0;
  string s;
  cout << "Read" << endl;
  while (cin >> s) {
    vec.push_back(s);
  }
  cout << "Search" << endl;
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec[0].size(); j++) {
      if (vec[i][j] != 'A')
        continue;
      res += searchWord(vec, i, j);
    }
  }
  cout << res << endl;
}
