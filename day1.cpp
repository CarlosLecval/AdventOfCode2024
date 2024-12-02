#include <bits/stdc++.h>
#include <iostream>

using namespace std;


void partOne() {
    freopen("input.txt", "r", stdin);
    int x, y;
    int sum = 0;
    vector<int> left;
    vector<int> right;
    
    while (cin >> x >> y) {
        left.push_back(x);
        right.push_back(y);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for(int i = 0; i < left.size(); i++) {
        sum += abs(left[i] - right[i]);
    }
    cout << sum << endl;
}

void partTwo() {
    freopen("input.txt", "r", stdin);
    int x, y;
    int sum = 0;
    vector<int> left;
    unordered_map<int, int> right;
    
    while (cin >> x >> y) {
        left.push_back(x);
        right[y]++;
    }
    for(int i = 0; i < left.size(); i++) {
        sum += left[i] * right[left[i]];
    }
    cout << sum << endl;
}

int main()
{
    partTwo();
}
