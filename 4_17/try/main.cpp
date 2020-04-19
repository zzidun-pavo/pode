#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a = {1,1,1,1,1};
    cout << lower_bound(a.begin(), a.end(), 1) - a.begin();
}
