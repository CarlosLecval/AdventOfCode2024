#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string word = "MAS";

int searchHorizontal(vector<string> &vec, int &row, int &col) {
  int count = 0;
  int ind = 0;
  for (int i = 1; (i <= 4 && col + i < vec[0].size()); i++) {
    if (vec[row][col + i] != word[ind])
      break;
    ind++;
  }
  if (ind == 3)
    count++;
  ind = 0;
  for (int i = 1; (i <= 4 && col - i >= 0); i++) {
    if (vec[row][col - i] != word[ind])
      break;
    ind++;
  }
  if (ind == 3)
    count++;
  return count;
}

int searchVertical(vector<string> &vec, int &row, int &col) {
  int count = 0;
  int ind = 0;
  for (int i = 1; (i <= 4 && row + i < vec.size()); i++) {
    if (vec[row + i][col] != word[ind])
      break;
    ind++;
  }
  if (ind == 3)
    count++;
  ind = 0;
  for (int i = 1; (i <= 4 && row - i >= 0); i++) {
    if (vec[row - i][col] != word[ind])
      break;
    ind++;
  }
  if (ind == 3)
    count++;
  return count;
}

int searchDiagonal(vector<string> &vec, int &row, int &col) {
  int count = 0;
  int ind = 0;
  for (int i = 1; (i <= 4 && row - i >= 0 && col + i < vec[0].size()); i++) {
    if (vec[row - i][col + i] != word[ind])
      break;
    ind++;
  }
  if (ind == 3)
    count++;
  ind = 0;
  for (int i = 1; (i <= 4 && row + i < vec.size() && col + i < vec[0].size());
       i++) {
    if (vec[row + i][col + i] != word[ind])
      break;
    ind++;
  }
  if (ind == 3)
    count++;
  ind = 0;
  for (int i = 1; (i <= 4 && row - i >= 0 && col - i >= 0); i++) {
    if (vec[row - i][col - i] != word[ind])
      break;
    ind++;
  }
  if (ind == 3)
    count++;
  ind = 0;
  for (int i = 1; (i <= 4 && row + i < vec.size() && col - i >= 0); i++) {
    if (vec[row + i][col - i] != word[ind])
      break;
    ind++;
  }
  if (ind == 3)
    count++;
  return count;
}

int searchWord(vector<string> &vec, int &row, int &col) {
  int counter = 0;
  counter += searchHorizontal(vec, row, col);
  counter += searchVertical(vec, row, col);
  counter += searchDiagonal(vec, row, col);
  return counter;
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
      if (vec[i][j] != 'X')
        continue;
      res += searchWord(vec, i, j);
    }
  }
  cout << res << endl;
}
