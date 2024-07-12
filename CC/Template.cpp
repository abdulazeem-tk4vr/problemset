#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long
#define ar array

int solve(int x, int y, int k) {
    while(k--){
        x++;
        while(x%y==0){
            x=x/y;
        }
    }
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // For multiple test cases, read input
    cin >> t;
    while(t--) {
        int x,y,k;
        cin >> x >> y >> k;
        cout<<solve(x,y,k)<<endl;
    }

    return 0;
}

