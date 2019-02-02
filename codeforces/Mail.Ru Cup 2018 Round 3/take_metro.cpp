#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100000

vector<int> bigStops(1);
int bigStopPosition[N];
bool moveClockWise[N];

int NextStop(int n, int i, ll t){
    t %= n;
    return moveClockWise[i] ? (i + t) % n : (i + n - t) % n;
}

int NextBigStop(int n, int i){
    for(ll t = n - 1; t > 0; --t){
        i = NextStop(n, i, t);
    }
    return i;
}

bool AddNewBigStop(int s){
    if(bigStopPosition[s]){
        return false;
    }
    bigStopPosition[s] = bigStops.size();
    bigStops.push_back(s);
    return true;
}

int main(){
    int n, m, s;
    ll t;

    cin >> n >> m >> s >> t;

    for(int i = 0; i < m; ++i){
        moveClockWise[i] = 1;
    }

    --s;

    for( ; t % n != 0; --t){
        s = NextStop(n, s, t);
    }

    AddNewBigStop(s);

    for(bool cycleFound = 0; t > 0 && cycleFound == 0; t -= n){
        s = NextBigStop(n, s);
        cycleFound = !AddNewBigStop(s);
    }

    t /= n;

    t %= (bigStops.size() - bigStopPosition[s]);

    int ans = bigStops[bigStopPosition[s] + t] + 1;

    cout << ans << '\n';

    return 0;
}