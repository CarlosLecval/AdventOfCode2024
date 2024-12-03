#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int count = 0;
    int number;
    int prevNumber;
    int difference;
    string s;
    while (getline(cin, s)) {
        bool isIncreasing;
        bool isSafe = true;
        istringstream stream(s);
        
        stream >> prevNumber;
        stream >> number;
        difference = prevNumber - number;
        if(difference > 3 || difference < -3 || difference == 0) continue;
        isIncreasing = difference > 0;
        prevNumber = number;

        while (stream >> number) {
            difference = prevNumber - number;
            if(difference > 3 || difference < -3 || difference == 0 || isIncreasing != (difference > 0)) {
                isSafe = false;
                break;
            }
            prevNumber = number;
        }
        if(!isSafe) continue;
        count++;
    }
    cout << count << endl;
}
